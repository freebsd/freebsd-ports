diff -ru src/info.c src/info.c
--- src/info.c Mon Jul 21 09:10:46 2003
+++ src/info.c Mon Jul 21 09:11:08 2003
@@ -25,7 +25,7 @@

 #include <unistd.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <X11/Xlib.h>

 #include "weewm.h"

