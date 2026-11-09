--- SleepLib/common.cpp.orig	2026-11-08 22:52:04 UTC
+++ SleepLib/common.cpp
@@ -353,7 +353,7 @@ QString appResourcePath()
     // This one will be used if the Html and Translations folders
     // are in the same folder as  the OSCAR executable
     paths.append( QCoreApplication::applicationDirPath() );
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QString appName = getAppName();
     if (appName == STR_AppName)
         appName = QString("OSCAR20");
