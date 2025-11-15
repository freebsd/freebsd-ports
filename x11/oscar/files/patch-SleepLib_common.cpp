--- SleepLib/common.cpp	2025-07-20 16:34:44.000000000 +0200
+++ SleepLib/common.cpp	2025-10-25 02:20:32.076356000 +0200
@@ -285,7 +285,7 @@
     // This one will be used if the Html and Translations folders
     // are in the same folder as  the OSCAR executable
     paths.append( QCoreApplication::applicationDirPath() );
-#ifdef Q_OS_LINUX 
+#if defined (Q_OS_LINUX) || defined (Q_OS_FREEBSD)
     QString appName = QCoreApplication::applicationName();
     if (appName != QString("OSCAR"))
         appName = QString("OSCAR-test");
