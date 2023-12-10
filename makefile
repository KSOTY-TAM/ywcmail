# MAKEFILE FOR ywcmail
CC=gcc
#CC=/usr/uClibc/bin/gcc
CFLAGS = -Wall -O2 -s
#LDFLAGS = -static
#The following LDFLAGS might be needed for Solaris
#LDFLAGS = -lsocket -lnsl
OBJECTS = cgi-lib.o main.o wmmain.o wmserver.o files.o logging.o

all:
	make clean
	make webmail.cgi

webmail.cgi: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o webmail.cgi
	@echo
	@echo "Copy webmail.cgi to your web server's cgi-bin directory,"
	@echo "ie. 'cp -a webmail.cgi /home/httpd/cgi-bin'."
	@echo "Copy webmail/ to your web server's htdocs directory,"
	@echo "ie. 'cp -a webmail /home/httpd/'."
	@echo

clean:
	rm -f webmail.cgi *.o *~

install:
	@echo
	@echo "There is no install.  Copy webmail.cgi to your web server's cgi-bin directory,"
	@echo "ie. 'cp -a webmail.cgi /home/httpd/public_html/cgi-bin'."
	@echo "Copy webmail/ to your web server's htdocs directory,"
	@echo "ie. 'cp -a webmail /home/httpd/public_html'."
	@echo
