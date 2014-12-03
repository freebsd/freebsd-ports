--- src/backends/meta-cursor-renderer.h.orig	2014-10-02 16:29:20.000000000 +0200
+++ src/backends/meta-cursor-renderer.h	2014-11-23 16:44:45.685535555 +0100
@@ -30,7 +30,9 @@
 #include <meta/screen.h>
 #include "meta-cursor.h"
 
+#if defined(HAVE_NATIVE_BACKEND)
 #include <gbm.h>
+#endif
 
 #define META_TYPE_CURSOR_RENDERER            (meta_cursor_renderer_get_type ())
 #define META_CURSOR_RENDERER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), META_TYPE_CURSOR_RENDERER, MetaCursorRenderer))
