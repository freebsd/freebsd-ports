--- EncodeBuffer.C.orig	Wed Mar  1 05:46:52 2006
+++ EncodeBuffer.C	Thu Apr 13 12:16:46 2006
@@ -13,9 +13,9 @@
 
 // #define DEBUG
 #ifdef DEBUG
-# define DBG(fmt, ...) printf(fmt, __VA_ARGS__)
+# define DBG(fmt, ARGS...) printf(fmt, ##ARGS)
 #else
-# define DBG(fmt,...)
+# define DBG(fmt, ARGS...)
 #endif
 
 static const int INITIAL_BUFFER_SIZE = 256;
