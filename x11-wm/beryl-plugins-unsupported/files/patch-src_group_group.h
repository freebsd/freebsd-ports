--- src/group/group.h.orig	Fri Jun  8 14:55:34 2007
+++ src/group/group.h	Fri Jun  8 14:56:21 2007
@@ -28,7 +28,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <time.h>
 #include <X11/Xlib.h>
 #include <cairo-xlib-xrender.h>
