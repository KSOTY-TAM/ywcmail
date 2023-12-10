/*
    ywcmail -- simple pop3/smtp web e-mail cgi
    Copyright (C) 2002  Chan Yin Chi < 0330@bigfoot.com >
    code based on null webmail
    Additional Code Copyright (C) 2016 < kt3@gmx.co.uk>
*/

#include <ctype.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#ifdef WIN32
	#pragma comment(lib, "wsock32.lib")
	#include <winsock.h>
	#include <io.h>
	#include <sys/timeb.h>
	#define snprintf _snprintf
	#define vsnprintf _vsnprintf
	#define strcasecmp stricmp
	#define strncasecmp strnicmp
#else
	#include <dirent.h>
	#include <netdb.h>
	#include <paths.h>
	#include <syslog.h>
	#include <unistd.h>
	#include <netinet/in.h>
	#include <sys/resource.h>
	#include <sys/socket.h>
	#include <sys/time.h>
	#include <sys/wait.h>
#endif
#include "config.h"

#define RFC1123FMT "%a, %d %b %Y %H:%M:%S GMT"

typedef struct {
	char From[128];
	char Replyto[128];
	char To[512];
 	char Date[128];
	char Subject[128];
	char CC[1024];
	char contenttype[256];
	char boundary[128];
	char encoding[128];
} wmheader;
typedef struct {
	char ClientIP[16];
	char Connection[128];
	int  ContentLength;
	char ContentType[128];
	char Cookie[1024];
	char Host[64];
	char PathInfo[128];
	char *PostData;
	char QueryString[1024];
	char Referer[128];
	char RequestMethod[8];
	char RequestURI[1024];
	char ScriptName[128];
	char UserAgent[128];
} request_struct;
request_struct request;
extern char **environ;
int  connected;
char wmusername[64];
char wmpassword[64];
char wmservertype[6];
char wmpop3server[64];
char wmsmtpserver[64];
int  wmsocket;

#ifdef SUPPORT_IMAP
typedef struct {
        int  wmimapidx;
        char wmimapfolder[48];
        char wmimapfolderlist[64][48];
} wmimapsession_struct;
wmimapsession_struct wmimapsession;
#endif


/* main.c stuff */
void printheader(void);
/* cgi-lib.c functions */
int  IntFromHex(char *pChars);
void URLDecode(unsigned char *pEncoded);
char *str2html(char *instring);
void cgi_readenv(void);
void cgi_readpost(void);
char *getgetenv(char *query);
char *getmimeenv(char *query);
char *getpostenv(char *query);
char *get_mime_type(char *name);
char *strcasestr(const char *src, const char *query);
void striprn(char *string);
/* wmmain.c functions */
int EncodeBase64(char *src, int srclen);
int  DecodeBase64(char *src, char *ctype);
int  wmprintf(const char *format, ...);
int  wmfgets(char *buffer, int max, int fd);
void wmclose(void);
void wmexit(void);
void send_header(int cacheable, int status, char *title, char *extra_header, char *mime_type, int length, time_t mod);
void wmcookieget(void);
int  wmcookieset(void);
void wmcookiekill(void);
void webmailread(void);
void webmailraw(void);
void webmailfiledl(void);
void webmailwrite(void);
void webmaillist(void);
void webmailsend(void);
void webmaildelete(void);
/* wmserver.c functions */
int  wmserver_connect(void);
void wmserver_disconnect(void);
int  wmserver_smtpconnect(void);
int  wmserver_smtpauth(void);
void wmserver_smtpdisconnect(void);
int  wmserver_count(void);
int  wmserver_msgdele(int message);
int  wmserver_msghead(int message);
int  wmserver_msgretr(int message);
int  wmserver_msgsize(int message);
int  wmserver_uidl(int message, char *uidl);
int is_msg_end(char *buffer);

inline void logdata(const char* type, const char* source_file, const char* method, const char *format, ...);
//#define LOGGING(...)
#define LOGGING(...) do { logdata( "LOG", c_file_name, c_func_name, __VA_ARGS__); } while (0)
//#define LOGGING_DISPLAY(...)
#define LOGGING_DISPLAY(...) do { logdata( "DISP", c_file_name, c_func_name, __VA_ARGS__); } while (0)
//#define LOGGING_DISPLAY(...)
#define LOGGING_TRACE(...) do { logdata( "TRAC", c_file_name, c_func_name, __VA_ARGS__); } while (0)
//#define LOGGING_DISPLAY(...)
#define LOGGING_WMGETS(...) do { logdata( "GET", c_file_name, c_func_name, __VA_ARGS__); } while (0)
