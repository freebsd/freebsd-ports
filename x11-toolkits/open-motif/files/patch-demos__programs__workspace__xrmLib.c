--- ./demos/programs/workspace/xrmLib.c.orig	2016-03-15 19:52:10.000000000 -0700
+++ ./demos/programs/workspace/xrmLib.c	2016-03-16 22:01:43.990986434 -0700
@@ -30,7 +30,7 @@
 #endif
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <Xm/Xm.h>
 #include "wsm.h"
 #include "wsmDebug.h"
