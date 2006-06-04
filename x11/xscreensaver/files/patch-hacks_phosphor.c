--- hacks/phosphor.c.orig	Fri Mar 31 19:50:00 2006
+++ hacks/phosphor.c	Sun Jun  4 00:01:46 2006
@@ -41,6 +41,10 @@
 # ifdef HAVE_UTIL_H
 #  include <util.h>
 # endif
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
 #endif /* HAVE_FORKPTY */
 
 #include "screenhack.h"
