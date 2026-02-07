--- DecodeBuffer.C.orig	Wed Mar  1 05:46:52 2006
+++ DecodeBuffer.C	Thu Apr 13 12:33:30 2006
@@ -1,6 +1,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stddef.h>
+#include <stdio.h>
 #include <assert.h>
 #include "DecodeBuffer.H"
 #include "IntCache.H"
@@ -20,9 +21,9 @@
 
 // #define DEBUG
 #ifdef DEBUG
-# define DBG(fmt, ...) printf(fmt, __VA_ARGS__)
+# define DBG(fmt, ARGS...) printf(fmt, ##ARGS)
 #else
-# define DBG(fmt,...)
+# define DBG(fmt, ARGS...)
 #endif
 
 DecodeBuffer::DecodeBuffer(const unsigned char *data, unsigned int length)
