--- src/backends/meta-cursor-private.h.orig	2014-11-23 16:45:02.933406434 +0100
+++ src/backends/meta-cursor-private.h	2014-11-23 16:45:36.450634686 +0100
@@ -25,7 +25,9 @@
 #include "meta-cursor.h"
 
 #include <cogl/cogl.h>
+#if defined(HAVE_NATIVE_BACKEND)
 #include <gbm.h>
+#endif
 
 typedef struct {
   CoglTexture2D *texture;
