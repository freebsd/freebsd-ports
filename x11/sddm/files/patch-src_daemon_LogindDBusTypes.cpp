Disable ConsoleKit seat management for now.  It is mistakenly assumed to have
the same D-Bus interface as logind.

--- src/daemon/LogindDBusTypes.cpp.orig	2017-12-05 16:00:16 UTC
+++ src/daemon/LogindDBusTypes.cpp
@@ -58,6 +58,7 @@ LogindPathInternal::LogindPathInternal()
         return;
     }
 
+    if (0)
     if (QDBusConnection::systemBus().interface()->isServiceRegistered(QStringLiteral("org.freedesktop.ConsoleKit"))) {
         qDebug() << "Console kit interface found";
         available = true;
