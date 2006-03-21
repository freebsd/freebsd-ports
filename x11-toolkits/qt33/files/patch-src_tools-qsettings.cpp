--- src/tools/qsettings.cpp.orig	Fri Sep  2 14:42:53 2005
+++ src/tools/qsettings.cpp	Mon Mar 20 18:36:27 2006
@@ -500,7 +500,12 @@
     } );
 #endif // Q_OS_TEMP
 #else
+  if (getenv( "TMPDIR" ) != 0) {
+    defPath = QString( getenv( "TMPDIR" ) );
+  }
+  else {
     defPath = qInstallPathSysconf();
+  }
 #endif
     QDir dir(appSettings);
     if (! dir.exists()) {
