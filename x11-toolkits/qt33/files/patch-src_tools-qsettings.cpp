--- src/tools/qsettings.cpp.orig	2007-02-02 09:01:03.000000000 -0500
+++ src/tools/qsettings.cpp	2011-08-12 03:41:18.000000000 -0400
@@ -34,6 +34,9 @@
 ** not clear to you.
 **
 **********************************************************************/
+#ifndef Q_WS_WIN
+#include <stdlib.h>
+#endif
 
 #include "qplatformdefs.h"
 
@@ -500,7 +503,12 @@
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
