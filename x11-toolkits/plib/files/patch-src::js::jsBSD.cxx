--- ./src/js/jsBSD.cxx.orig	Sat Mar 20 01:21:53 2004
+++ ./src/js/jsBSD.cxx	Sun May  2 16:53:28 2004
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
@@ -53,9 +57,14 @@
 #include <usb.h>
 #endif
 #elif defined(__FreeBSD__)
+#  if __FreeBSD_version < 500000
 extern "C" {
-#include <libusbhid.h>
+#    include <libusbhid.h>
 }
+#  else
+#    define HAVE_USBHID_H 1
+#    include <usbhid.h>
+#  endif
 #endif
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
