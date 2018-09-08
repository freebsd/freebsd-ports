On FreeBSD console-kit-daemon isn't started by the init system, so try to
start it from sddm.

--- src/daemon/DaemonApp.cpp.orig	2017-12-05 16:00:16 UTC
+++ src/daemon/DaemonApp.cpp
@@ -28,6 +28,7 @@
 
 #include "MessageHandler.h"
 
+#include <QDBusConnectionInterface>
 #include <QDebug>
 #include <QHostInfo>
 #include <QTimer>
@@ -48,6 +49,8 @@ namespace SDDM {
 
         // set testing parameter
         m_testing = (arguments().indexOf(QStringLiteral("--test-mode")) != -1);
+
+        QDBusConnection::systemBus().interface()->startService(QStringLiteral("org.freedesktop.ConsoleKit"));
 
         // create display manager
         m_displayManager = new DisplayManager(this);
