--- src/dumpkeys.c.orig	Fri Apr 30 10:16:53 2004
+++ src/dumpkeys.c	Thu May  6 10:46:19 2004
@@ -18,6 +18,7 @@
 
 #ident "$Id: dumpkeys.c,v 1.7 2004/04/30 01:16:53 nalin Exp $"
 #include "../config.h"
+#include <sys/types.h>
 #ifdef HAVE_SYS_SELECT_H
 #include <sys/select.h>
 #endif
@@ -25,7 +26,6 @@
 #include <sys/termios.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <signal.h>
