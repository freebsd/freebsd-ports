--- util/wmiv.c.orig	2014-09-05 04:35:03.000000000 +0900
+++ util/wmiv.c	2014-09-05 04:35:45.000000000 +0900
@@ -28,7 +28,9 @@
 #include <X11/Xlib.h>
 #include "wraster.h"
 #include <stdlib.h>
+#define	__BSD_VISIBLE	1
 #include <stdio.h>
+#undef __BSD_VISIBLE
 #include <string.h>
 #include <dirent.h>
 #include <limits.h>
