--- src/peksystray.c.orig	Thu Jul  8 13:01:08 2004
+++ src/peksystray.c	Thu Jul  8 13:02:21 2004
@@ -66,22 +66,21 @@
 void
 display_help ()
 {
-  fprintf (stdout, "
-%s - version %s
-Copyright 2003, Mohammed Sameer <uniball@linux-egypt.org>
-
-Usage: %s [OPTIONS]
-
-Options:
- --help\t Display this help.
- --version\t Display version number and exit.
- --display DISPLAY\t The X display to connect to.
- --icon-size SIZE\t Icon size. Default is 16.
- --vertical\t Vertical layout. Default is horizontal.
- --border SIZE\t Border width. Default is 0;
- --multiple\t Open each icon in a separate window. Default is no.
-
-", PACKAGE, VERSION, PACKAGE);
+  fprintf (stdout,
+"\n%s - version %s\n"
+"Copyright 2003, Mohammed Sameer <uniball@linux-egypt.org>\n"
+"\n"
+"Usage: %s [OPTIONS]\n"
+"\n"
+"Options:\n"
+" --help\t Display this help.\n"
+" --version\t Display version number and exit.\n"
+" --display DISPLAY\t The X display to connect to.\n"
+" --icon-size SIZE\t Icon size. Default is 16.\n"
+" --vertical\t Vertical layout. Default is horizontal.\n"
+" --border SIZE\t Border width. Default is 0;\n"
+" --multiple\t Open each icon in a separate window. Default is no.\n"
+"\n", PACKAGE, VERSION, PACKAGE);
   exit (0);
 }
 
