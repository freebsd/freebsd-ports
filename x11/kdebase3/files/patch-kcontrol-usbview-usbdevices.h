Patch included below. FreeBSD_version is approximate.

--- kcontrol/usbview/usbdevices.h.orig	2006-07-22 10:15:22.000000000 +0200
+++ kcontrol/usbview/usbdevices.h	2009-03-15 23:24:38.000000000 +0100
@@ -17,8 +17,13 @@
 #include <qptrlist.h>
 
 #ifdef Q_OS_FREEBSD
+#include <osreldate.h>
+#if __FreeBSD_version >= 800069
+#include <legacy/dev/usb/usb.h>
+#else
 #include <dev/usb/usb.h>
 #endif
+#endif
 
 class USBDB;
 
