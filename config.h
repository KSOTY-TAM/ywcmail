/*
    ywcmail -- simple pop3/smtp web e-mail cgi
    Copyright (C) 2002 Chan Yin Chi < 0330@bigfoot.com >

*/
#define YWC_SERVERNAME	" ywcmail / 0.95"

/*
 * APPEND_ADDRESS will let you override the hostname part of return e-mail
 * addresses.  If you don't need it, then don't use it.  You probably will
 * want to use this if the return address domain name is more than two levels.
 * If the username is the full return address (ie, virtual mail systems),
 * you may want to define APPEND_ADDRESS as a blank string.  If you don't use
 * APPEND_ADDRESS, your return address will be the top two levels of the pop3
 * host's name.
 */
#define APPEND_ADDRESS	"@yingwa.edu.hk"

/*
 * If #defined, NO_USER_HOSTS will remove the user's ability to choose their
 * own host names.  Be sure to set POP3_HOST and SMTP_HOST correctly if you
 * choose to use this option.
 */
#define NO_USER_HOSTS

/*
 * BASE_IMAGE_URL tells the cgi where the images are.  STYLESHEET can be used
 * to point to any CSS file you may want to use.
 */
#define BASE_IMAGE_URL	"/webmail/"
#define STYLESHEET	"/webmail/style.css"

/*
 * These colour #defines allow easy customization of may of the colours used
 * in the CGI.  Some of these colours may be overridded if a stylesheet is in
 * use (i.e. COLOR_TRIM and COLOR_TRIMTEXT).
 */
#define COLOR_EDITFORM	"#E0E0E0"
#define COLOR_FTEXT	"#F0F0F0"
#define COLOR_LINKS	"#0000FF"
#define COLOR_TRIM	"#000050"
#define COLOR_TRIMTEXT	"#FFFFFF"

/*
 * If there are more than MAX_LIST_SIZE messages, the message list will be
 * broken up into multiple pages.
 */
#define MAX_LIST_SIZE	20

/*
 * This setting is not an inactivity timer, but instead limits the absolute
 * maximum time in seconds that the cgi is allowed to run.
 */
#define MAX_RUNTIME	1800
/*
 * POP3_HOST and SMTP_HOST really should be changed to reflect the fully
 * qualified domain names of the mail servers.  The port settings typically
 * shouldn't need to be changed.
 */
#define POP3_HOST	"localhost"
#define SMTP_HOST	"localhost"
#define IMAP_PORT	143
#define POP3_PORT	110
#define SMTP_PORT	25

/*
 * You MUST support either POP3, IMAP, or both, otherwise the CGI doesn't work.
 * IMAP support is still highly experimental right now, so I recommend against
 * using it.
 */
//#define SUPPORT_IMAP
#define SUPPORT_POP3

/*
 * SMTP_AUTH enables plain auth with smtp servers using the pop3/imap username
 * and password.
 */
//#define SMTP_AUTH

/*
 * MAX_POSTSIZE limits the total size of allowable POSTS, and as a result can
 * be used to control the maximum size of a message and/or attachments.
 */
#define MAX_POSTSIZE	50554432 /* 50 MB limit for allowed POST sizes */

#define RAW_MESSAGES
#define USE_FRAMES
#define USE_SYSLOG

/*
 * If you want to change the language, uncomment the appropriate strings header
 * file here.  #include one, and only one strings file.
 */
 #include "i18n/strings-en.h"	// English
// #include "i18n/strings-zh_TW.h"	// Traditional Chinese
// # include "i18n/strings-zh_CN.h"     // Simplified Chinese

//Users allowed to access yingwa mail
#define ALLOWED_USERS "/usr/local/yingwa/allow"

#define LOG_FILENAME "/usr/local/apache/htdocs/webmail_main_log.txt"

