--- src/compositor/meta-texture-rectangle.c.orig	2013-11-23 13:42:35.000000000 +0000
+++ src/compositor/meta-texture-rectangle.c	2014-03-31 08:00:34.766125773 +0000
@@ -35,10 +35,8 @@
 meta_texture_rectangle_new (unsigned int width,
                             unsigned int height,
                             CoglPixelFormat format,
-                            CoglPixelFormat internal_format,
                             unsigned int rowstride,
-                            const guint8 *data,
-                            GError **error)
+                            const guint8 *data)
 {
   ClutterBackend *backend =
     clutter_get_default_backend ();
@@ -46,10 +44,7 @@
     clutter_backend_get_cogl_context (backend);
   CoglTextureRectangle *tex_rect;
 
-  tex_rect = cogl_texture_rectangle_new_with_size (context,
-                                                   width, height,
-                                                   internal_format,
-                                                   error);
+  tex_rect = cogl_texture_rectangle_new_with_size (context, width, height);
   if (tex_rect == NULL)
     return NULL;
 
