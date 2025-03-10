--- src/mesa/util/libsync.h.orig	2024-01-08 20:00:59 UTC
+++ src/mesa/util/libsync.h
@@ -30,6 +30,9 @@
 
 #include <assert.h>
 #include <errno.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 #include <stdbool.h>
 #include <stdint.h>
 #include <string.h>
