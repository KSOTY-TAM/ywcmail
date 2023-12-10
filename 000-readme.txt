YWCMAIL 0.96  
------------
2016 < kt3@gmx.co.uk > 

Welcome to this upgrade to ywcmail 0.95. Please email me with any questions or comments.

This release has some additional functionality:

No one can login to ywcmail unless their name is listed in a file specified in config.h:

  #define ALLOWED_USERS "/usr/local/yingwa/allow"

i.e. the file allow contains a list of permitted login usernames. Make sure you put the file outside of the public_html and cgi-bin file structures. The file contents should look like this, in this example anon is a username that has a pop3 or imap account on the server and is allowed to use the webmail application:

  # A list of login usernames that can access yingwa mail
  #   in the simplest implementation these usernames map to the     
      usernames used to access the POP/IMAP mailboxes
  
  anon


This release has some fixes applied:

1. Version 0.95 could not cope with headers that wrapped onto the following line. This has been resolved.

2. Version 0.95 got into difficulties with complex nested MIME parts.  Changes in 0.96 enable the viewing of these messages.

3. Downloading filenames containing '+' did not work.

4. In the maillist screen, Version 0.95 did not display some kinds of From addresses.

5. striprn() was being called unnecessarily in wmmain.c

Notes
-----

Be aware the application does not support folding as per RFC 2822 2.2.3 because wmfgets() does not allow a line to be read with <CR><LF><WSP><CR><LF>
