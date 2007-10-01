--- frontend/common/src/System.cc.orig	2007-09-28 13:18:31.000000000 -0300
+++ frontend/common/src/System.cc	2007-09-28 13:18:48.000000000 -0300
@@ -28,6 +28,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <strings.h>
+#include <sys/wait.h>
 
 #include "System.hh"
 #include "debug.hh"
