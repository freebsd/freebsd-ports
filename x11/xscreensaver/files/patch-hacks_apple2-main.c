--- hacks/apple2-main.c.orig	Sun Mar 26 21:34:17 2006
+++ hacks/apple2-main.c	Sun Jun  4 00:01:46 2006
@@ -39,6 +39,10 @@
 # ifdef HAVE_UTIL_H
 #  include <util.h>
 # endif
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
 #endif /* HAVE_FORKPTY */
 
 #include "screenhack.h"
