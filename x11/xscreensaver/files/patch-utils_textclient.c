--- utils/textclient.c.orig	2016-04-28 02:29:36 UTC
+++ utils/textclient.c
@@ -55,6 +55,7 @@
 # ifdef HAVE_SYS_TERMIOS_H
 #  include <sys/termios.h>
 # endif
+# include <libutil.h>
 #endif /* HAVE_FORKPTY */
 
 #undef DEBUG
