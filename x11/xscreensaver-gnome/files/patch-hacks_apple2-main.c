--- hacks/apple2-main.c.orig	Wed May 19 21:45:49 2004
+++ hacks/apple2-main.c	Wed May 19 21:46:13 2004
@@ -30,6 +30,10 @@
 # ifdef HAVE_UTIL_H
 #  include <util.h>
 # endif
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
 #endif /* HAVE_FORKPTY */
 
 #undef countof
