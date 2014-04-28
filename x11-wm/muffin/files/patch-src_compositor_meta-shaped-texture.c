--- src/compositor/meta-shaped-texture.c.orig	2014-03-31 10:15:32.429567385 +0000
+++ src/compositor/meta-shaped-texture.c	2014-03-31 10:15:38.680567395 +0000
@@ -295,10 +295,8 @@
       if (meta_texture_rectangle_check (paint_tex))
         priv->mask_texture = meta_texture_rectangle_new (tex_width, tex_height,
                                                          COGL_PIXEL_FORMAT_A_8,
-                                                         COGL_PIXEL_FORMAT_A_8,
                                                          stride,
-                                                         mask_data,
-                                                         NULL /* error */);
+                                                         mask_data);
       else
         priv->mask_texture = cogl_texture_new_from_data (tex_width, tex_height,
                                                          COGL_TEXTURE_NONE,
