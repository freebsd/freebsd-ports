--- src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp.orig	2019-06-13 04:18:18 UTC
+++ src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp
@@ -52,11 +52,7 @@
 #include <QtGui/private/qguiapplication_p.h>
 #include <QtGui/private/qinputdevicemanager_p.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 QT_BEGIN_NAMESPACE
 
