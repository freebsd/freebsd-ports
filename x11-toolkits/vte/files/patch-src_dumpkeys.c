--- src/dumpkeys.c.orig	Fri Apr 30 10:16:53 2004
+++ src/dumpkeys.c	Thu May  6 10:46:19 2004
@@ -18,6 +18,7 @@
 
 #ident "$Id: patch-src_dumpkeys.c,v 1.5 2004/11/01 04:45:09 marcus Exp $"
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
