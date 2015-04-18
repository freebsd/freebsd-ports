--- src/xshmfence_futex.h.orig	2014-06-17 16:46:42.000000000 -0400
+++ src/xshmfence_futex.h	2015-04-18 12:16:21.953572000 -0400
@@ -28,6 +28,7 @@
 
 #ifdef HAVE_UMTX
 
+#include <sys/limits.h>
 #include <sys/types.h>
 #include <sys/umtx.h>
 
