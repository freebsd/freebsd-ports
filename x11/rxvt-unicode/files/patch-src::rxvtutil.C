--- ./src/rxvtutil.C.orig	Mon Aug 16 01:11:46 2004
+++ ./src/rxvtutil.C	Tue Aug 17 23:15:04 2004
@@ -4,6 +4,7 @@
 
 #include "rxvtutil.h"
 
+#ifdef HAVE_SYS_BYTEORDER_H
 class byteorder byteorder;
 
 byteorder::byteorder ()
@@ -20,6 +21,6 @@
 
   e = w.u;
 }
-
+#endif
 
 
