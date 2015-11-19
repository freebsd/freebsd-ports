--- xpra/codecs/buffers/memalign.c.orig	2015-04-30 15:00:04 UTC
+++ xpra/codecs/buffers/memalign.c
@@ -13,7 +13,7 @@
 #ifdef _WIN32
 #define _STDINT_H
 #endif
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 #include <malloc.h>
 #endif
 
