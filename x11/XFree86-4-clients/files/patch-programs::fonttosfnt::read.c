--- programs/fonttosfnt/read.c.orig	Fri Apr  9 22:31:49 2004
+++ programs/fonttosfnt/read.c	Fri Apr  9 22:32:24 2004
@@ -28,7 +28,7 @@
 #include FT_BDF_H
 #include "X11/Xos.h"
 #include "fonttosfnt.h"
-#include "fontenc.h"
+#include "X11/fonts/fontenc.h"
 
 #define FLOOR2(x, y) ((x) >= 0 ? (x) / (y) : -(((-(x)) + (y) - 1) / (y)))
 #define CEIL2(x, y) (FLOOR2((x) + (y) - 1, (y)))
