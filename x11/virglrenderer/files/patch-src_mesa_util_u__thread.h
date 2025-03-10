--- src/mesa/util/u_thread.h.orig	2024-01-08 20:00:59 UTC
+++ src/mesa/util/u_thread.h
@@ -43,6 +43,10 @@
 #endif
 #endif
 
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
+
 #ifdef __HAIKU__
 #include <OS.h>
 #endif
