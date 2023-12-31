/*
    ywcmail -- simple pop3/smtp web e-mail cgi
    Copyright (C) 2002 Chan Yin Chi < 0330@bigfoot.com >
    Translation by Yourname <you@somewhere.com>

*/
#define ERR_NOUSER	"User name and password cannot be blank"
#define ERR_NOHOST	"Missing server names"
#define ERR_NOWINSOCK	"Winsock initialization failed"
#define ERR_DNS_POP3	"Could not find POP3 server"
#define ERR_DNS_SMTP	"Could not find SMTP server"
#define ERR_CON_POP3	"Could not connect to POP3 server"
#define ERR_CON_SMTP	"Could not connect to SMTP server"
#define ERR_NORECIPIENT	"No recipient specified - Message was not sent"
#define ERR_BIGPOST	"Bad Request - POST too large"
#define ERR_BADURI	"Bad Request - Malformed URI"
#define ERR_INVALIDURI	"Bad Request - Invalid specification"
#define ERR_NOMESSAGE	"Bad Request - No such message"
#define ERR_NOBOUNDARY	"Bad Request - Can't find the MIME boundary"
#define ERR_NOFILES	"Bad Request - No files are attached to this message"
#define ERR_NOFILE	"Bad Request - File not found"
#define ERR_NOFRAMES	"ywcmail requires frames"
#define LOGIN_TITLE	"ywcmail / 0.95 Login"
#define LOGIN_USERNAME	"Login Name"
#define LOGIN_PASSWORD	"Password"
#define LOGIN_POP3HOST	"POP3 Server"
#define LOGIN_SMTPHOST	"SMTP Server"
#define LOGOUT_TITLE	"ywcmail 0.95 Logout"
#define LOGOUT_MESSAGE \
"You have successfully logout.<BR>\n"
#define YWC_TOP_INBOX	"INBOX"
#define YWC_TOP_COMPOSE	"COMPOSE"
#define YWC_TOP_LOGOUT	"LOG OUT"
#define YWC_NOMAIL	"You have no messages in your mailbox."
#define YWC_PREVIOUS	"Previous"
#define YWC_NEXT	"Next"
#define YWC_FROM	"From"
#define YWC_TO		"To"
#define YWC_SUBJECT	"Subject"
#define YWC_DATE	"Date"
#define YWC_SIZE	"Size"
#define YWC_SELECTALL	"Select all messages"
#define YWC_DELSELECTED	"Delete selected messages"
#define YWC_REPLY	"Reply"
#define YWC_FORWARD	"Forward"
#define YWC_DELETE	"Delete"
#define YWC_VIEW_SRC	"View source"
#define YWC_ATTACHMENTS	"Attachments"
#define YWC_CC		"CC"
#define YWC_BCC		"BCC"
#define YWC_FILE	"File"
#define YWC_REPLYLINE	"--- %s wrote:\n"
#define YWC_FWD_FROM	"> From:    %s\n"
#define YWC_FWD_SUBJECT	"> Subject: %s\n"
#define YWC_FWD_DATE	"> Date:    %s\n"
#define YWC_SENDMAIL	"Send Mail"
#define YWC_SENDINGFILE	"Sending file '%s' (%d bytes)<BR>\n"
#define YWC_DELETING	"Deleting message %d..."
#define YWC_DELETE_OK	"success."
#define YWC_DELETE_BAD	"failure."
#define YWC_MIME	"This is a multi-part message in MIME format."
#define YWC_SMTP_FROMOK	"Sender '%s' OK.<BR>\n"
#define YWC_SMTP_RCPTOK	"Recipient '%s' OK.<BR>\n"
#define YWC_SMTP_SENT	"Message Sent."
