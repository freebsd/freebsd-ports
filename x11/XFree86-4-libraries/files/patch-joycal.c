--- ./programs/Xserver/hw/xfree86/etc/joycal.c.orig	Sat Nov 22 09:00:18 1997
+++ ./programs/Xserver/hw/xfree86/etc/joycal.c	Mon Apr  8 15:08:17 2002
@@ -6,7 +6,7 @@
 #include <unistd.h>
 #include <string.h>
 #if defined (__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
-#include <machine/joystick.h>
+#include <sys/joystick.h>
 #define JS_RETURN sizeof(struct joystick)
 #define JS_DATA_TYPE joystick
 #define button_down(j) (j.b1 | j.b2)
