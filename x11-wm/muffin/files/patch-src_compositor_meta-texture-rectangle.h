--- src/compositor/meta-texture-rectangle.h.orig	2013-11-23 13:42:35.000000000 +0000
+++ src/compositor/meta-texture-rectangle.h	2014-03-31 08:00:34.766125773 +0000
@@ -34,10 +34,8 @@
 meta_texture_rectangle_new (unsigned int width,
                             unsigned int height,
                             CoglPixelFormat format,
-                            CoglPixelFormat internal_format,
                             unsigned int rowstride,
-                            const guint8 *data,
-                            GError **error);
+                            const guint8 *data);
 
 gboolean
 meta_texture_rectangle_check (CoglTexture *texture);
