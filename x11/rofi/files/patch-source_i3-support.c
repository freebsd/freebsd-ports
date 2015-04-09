--- source/i3-support.c.orig	2015-02-27 14:12:52 UTC
+++ source/i3-support.c
@@ -36,7 +36,7 @@
 #include <X11/X.h>
 #include <X11/Xlib.h>
 #include <sys/socket.h>
-#include <linux/un.h>
+#include <sys/un.h>
 
 #include "rofi.h"
 #include "x11-helper.h"
