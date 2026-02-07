--- src/config.h.orig	2020-05-02 17:22:39 UTC
+++ src/config.h
@@ -74,6 +74,8 @@
 #ifdef Q_OS_MACOS
 // Qt does not support fontconfig on macOS, so we need to use a "real" font name.
 #define DEFAULT_FONT                   "Menlo"
+#elif defined(Q_OS_FREEBSD)
+#define DEFAULT_FONT	    	       "Liberation Mono"
 #else
 #define DEFAULT_FONT                   "Monospace"
 #endif
