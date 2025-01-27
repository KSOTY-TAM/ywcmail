/*
  Logging routine
  Copyright (C) 2016 < kt3@gmx.co.uk>

*/

#include "config.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#ifdef USE_SYSLOG
  #include <syslog.h>
#endif

char* get_date( char* msgdate, unsigned int size_msgdate )
{
        struct timeval ttime;
        struct timezone tzone;
        char msgdatetz[100];

        //20161012 for compile time message about incompatible pointer type
        gettimeofday(&ttime, &tzone);

        time_t rawtime;
        rawtime = time(NULL);
        struct tm *tmp = localtime(&rawtime);
        strftime(msgdate, size_msgdate, "%a, %d %b %Y %H:%M:%S", tmp);
        snprintf(msgdatetz, sizeof(msgdatetz)-1, " %+.4d", -tzone.tz_minuteswest/60*100);
        strncat(msgdate, msgdatetz, size_msgdate-strlen(msgdate)-1);

        return msgdate;
}

inline void logdata(const char* type, const char* source_file, const char* method, const char *format, ...)
{
	char logbuffer[1024];
        char file[200];
        va_list ap;
        FILE *fp;

	pid_t pid;
	pid = getpid();

	char msgdate[100];

	snprintf(file, sizeof(file)-1, LOG_FILENAME);

	fp=fopen(file, "a");
	if (fp!=NULL) {
        	va_start(ap, format);
                vsnprintf(logbuffer, sizeof(logbuffer)-1, format, ap);
               	va_end(ap);
                fprintf(fp, "%d: %22.22s, %6.6s, %7.7s, %10.10s, %20.20s: %s\n", pid, (char*)get_date( msgdate, 100 ), "unknown", type, source_file, method, logbuffer);
                fclose(fp);
	}
        else
        {
		#ifdef USE_SYSLOG
                	syslog( LOG_MAIL|LOG_INFO, "Could not open log file %s, to write msg %s", LOG_FILENAME, logbuffer );
	    	#endif
        }
}