--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2019-06-13 04:18:18 UTC
+++ src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp
@@ -49,11 +49,7 @@
 #include <QtCore/private/qcore_unix_p.h>
 #include <QtGui/private/qhighdpiscaling_p.h>
 #include <QtGui/private/qguiapplication_p.h>
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 #include <math.h>
 
