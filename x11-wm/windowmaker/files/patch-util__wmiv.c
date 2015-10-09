--- util/wmiv.c.orig	2015-08-11 18:41:14 UTC
+++ util/wmiv.c
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
