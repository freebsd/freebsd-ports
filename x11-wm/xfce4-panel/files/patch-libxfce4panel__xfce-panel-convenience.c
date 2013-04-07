--- ./libxfce4panel/xfce-panel-convenience.c.orig	2012-04-28 20:31:35.000000000 +0000
+++ ./libxfce4panel/xfce-panel-convenience.c	2013-04-06 21:01:14.000000000 +0000
@@ -158,7 +158,7 @@
   gchar     *name;
   gchar     *filename;
   gint       src_w, src_h;
-  gdouble    wratio, hratio;
+  gdouble    ratio;
   GdkPixbuf *dest;
   GError    *error = NULL;
   gint       size = MIN (dest_width, dest_height);
@@ -170,15 +170,13 @@
 
   if (G_UNLIKELY (g_path_is_absolute (source)))
     {
-      pixbuf = gdk_pixbuf_new_from_file_at_scale (source, dest_width, dest_height, TRUE, &error);
+      pixbuf = gdk_pixbuf_new_from_file (source, &error);
       if (G_UNLIKELY (pixbuf == NULL))
         {
           g_message ("Failed to load image \"%s\": %s",
                      source, error->message);
           g_error_free (error);
         }
-
-      return pixbuf;
     }
   else
     {
@@ -233,13 +231,11 @@
       if (src_w > dest_width || src_h > dest_height)
         {
           /* calculate the new dimensions */
-          wratio = (gdouble) src_w / (gdouble) size;
-          hratio = (gdouble) src_h / (gdouble) size;
+          ratio = MIN ((gdouble) dest_width / (gdouble) src_w,
+                       (gdouble) dest_height / (gdouble) src_h);
 
-          if (hratio > wratio)
-            dest_width  = rint (src_w / hratio);
-          else
-            dest_height = rint (src_h / wratio);
+          dest_width  = rint (src_w * ratio);
+          dest_height = rint (src_h * ratio);
 
           dest = gdk_pixbuf_scale_simple (pixbuf,
                                           MAX (dest_width, 1),
