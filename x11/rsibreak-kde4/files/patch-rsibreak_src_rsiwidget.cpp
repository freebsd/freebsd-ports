--- rsibreak/src/rsiwidget.cpp.orig	Tue Mar 21 18:38:48 2006
+++ rsibreak/src/rsiwidget.cpp	Tue Mar 21 18:39:14 2006
@@ -41,6 +41,7 @@
 
 #include <stdlib.h>
 #include <math.h>
+#include <time.h>
 
 #include "rsiwidget.h"
 #include "rsitimer.h"
@@ -235,7 +236,7 @@
 
     QDir dir( folder);
 
-    if ( !dir.exists() or !dir.isReadable() )
+    if ( !dir.exists() || !dir.isReadable() )
     {
         kdWarning() << "Folder does not exist or is not readable: "
                 << folder << endl;
