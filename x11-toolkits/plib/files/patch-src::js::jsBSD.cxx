--- src/js/jsBSD.cxx.orig	Sat Mar 20 01:21:53 2004
+++ src/js/jsBSD.cxx	Thu Jun  3 17:06:30 2004
@@ -44,7 +44,11 @@
 #endif
 
 #include <sys/ioctl.h>
-#include <machine/joystick.h>		// For analog joysticks
+#if defined(__FreeBSD__)
+# include <sys/joystick.h>
+#else
+# include <machine/joystick.h>		// For analog joysticks
+#endif
 #ifdef HAVE_USB_JS
 #if defined(__NetBSD__)
 #ifdef HAVE_USBHID_H
@@ -54,7 +58,12 @@
 #endif
 #elif defined(__FreeBSD__)
 extern "C" {
-#include <libusbhid.h>
+#  if __FreeBSD_version < 500000
+#    include <libusbhid.h>
+#  else
+#    define HAVE_USBHID_H 1
+#    include <usbhid.h>
+#  endif
 }
 #endif
 #include <dev/usb/usb.h>
