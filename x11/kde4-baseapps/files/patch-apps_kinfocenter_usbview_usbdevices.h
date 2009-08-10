--- ./apps/kinfocenter/usbview/usbdevices.h.orig	2008-10-17 03:00:14.000000000 -0800
+++ ./apps/kinfocenter/usbview/usbdevices.h	2009-03-01 21:01:18.000000000 -0900
@@ -18,7 +18,12 @@
 #include <bus/usb/usb.h>
 #include <QStringList>
 #elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
+#include <sys/param.h>
+#if __FreeBSD_version >= 800061
+#include <legacy/dev/usb/usb.h>
+#else
 #include <dev/usb/usb.h>
+#endif
 #include <QStringList>
 #endif
 
