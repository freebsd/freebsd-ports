--- hacks/phosphor.c.orig	Wed May 19 21:43:52 2004
+++ hacks/phosphor.c	Wed May 19 21:44:54 2004
@@ -33,6 +33,10 @@
 # ifdef HAVE_UTIL_H
 #  include <util.h>
 # endif
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
 #endif /* HAVE_FORKPTY */
 
 extern XtAppContext app;
