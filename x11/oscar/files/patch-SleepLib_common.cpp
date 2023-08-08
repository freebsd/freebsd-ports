--- SleepLib/common.cpp
+++ SleepLib/common.cpp
@@ -248,7 +248,7 @@ QString appResourcePath()
     // This one will be used if the Html and Translations folders 
     // are in the same folder as  the OSCAR executable
     paths.append( QCoreApplication::applicationDirPath() );
-#ifdef Q_OS_LINUX    
+#if defined (Q_OS_LINUX) || defined (Q_OS_FREEBSD)
     QString appName = QCoreApplication::applicationName();
     if (appName != QString("OSCAR"))
         appName = QString("OSCAR-test");
