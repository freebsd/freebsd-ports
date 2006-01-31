--- src/tools/qsettings.cpp.orig	Fri Sep  2 14:42:53 2005
+++ src/tools/qsettings.cpp	Tue Jan 31 10:23:14 2006
@@ -500,7 +500,12 @@
     } );
 #endif // Q_OS_TEMP
 #else
-    defPath = qInstallPathSysconf();
+  if (getenv( "TMPDIR" ) != 0) {
+    defPath = QString( getenv( "TMPDIR" ) );
+  }
+  else {
+    defPath= "/tmp";
+  }
 #endif
     QDir dir(appSettings);
     if (! dir.exists()) {
