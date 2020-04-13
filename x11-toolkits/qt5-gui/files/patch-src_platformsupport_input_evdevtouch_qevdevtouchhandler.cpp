--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2019-12-31 20:34:48.636796000 +0100
+++ src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp	2019-12-31 20:35:13.274140000 +0100
@@ -52,11 +52,7 @@
 
 #include <mutex>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 #include <math.h>
 
