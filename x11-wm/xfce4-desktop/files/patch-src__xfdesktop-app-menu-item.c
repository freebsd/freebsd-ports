--- ./src/xfdesktop-app-menu-item.c.orig	2013-03-02 16:40:19.000000000 +0000
+++ ./src/xfdesktop-app-menu-item.c	2013-03-18 09:50:38.000000000 +0000
@@ -28,6 +28,10 @@
 #include <string.h>
 #endif
 
+#ifdef HAVE_MATH_H
+#include <math.h>
+#endif
+
 #include <gtk/gtk.h>
 
 #include <libxfce4util/libxfce4util.h>
@@ -169,8 +173,11 @@
 xfdesktop_app_menu_item_set_icon(XfdesktopAppMenuItem *app_menu_item)
 {
     const gchar *icon_name;
-    gint w, h, size;
+    gint w, h, size, new_size;
+    gint src_w, src_h;
+    gdouble wratio, hratio;
     GdkPixbuf *pixbuf = NULL;
+    GdkPixbuf *dest;
     GtkWidget *image = NULL;
     GtkIconTheme *icon_theme;
     gchar *p, *name = NULL;
@@ -187,7 +194,7 @@
             image = gtk_image_new_from_icon_name(icon_name, GTK_ICON_SIZE_MENU);
         else {
             if (g_path_is_absolute(icon_name)) {
-                pixbuf = gdk_pixbuf_new_from_file_at_scale(icon_name, w, h, TRUE, NULL);
+                pixbuf = gdk_pixbuf_new_from_file(icon_name, NULL);
             } else {
                 /* try to lookup names like application.png in the theme */
                 p = strrchr(icon_name, '.');
@@ -206,11 +213,41 @@
                 }
 
                 if(name) {
-                    pixbuf = gdk_pixbuf_new_from_file_at_scale(name, w, h, TRUE, NULL);
+                    pixbuf = gdk_pixbuf_new_from_file(name, NULL);
                     g_free(name);
                 }
             }
 
+            /* scale the pixbuf */
+            if(G_LIKELY(pixbuf)) {
+                /* 24x24 pixels looks good */
+                new_size = MIN(24, 24);
+
+                src_w = gdk_pixbuf_get_width(pixbuf);
+                src_h = gdk_pixbuf_get_height(pixbuf);
+
+                if(src_w > 24 || src_h > 24) {
+                    /* calculate the new dimensions */
+                    wratio = (gdouble) src_w / (gdouble) new_size;
+                    hratio = (gdouble) src_h / (gdouble) new_size;
+
+                    if(hratio == wratio) {
+                        w = rint(src_w / hratio);
+                        h = rint(src_h / hratio);
+                    }
+                    else if(hratio > wratio)
+                        w = rint(src_w / hratio);
+                    else
+                        h = rint(src_h / wratio);
+
+                    dest = gdk_pixbuf_scale_simple(pixbuf,
+                        MAX(w, 1), MAX(h, 1), GDK_INTERP_BILINEAR);
+
+                    g_object_unref(G_OBJECT(pixbuf));
+                    pixbuf = dest;
+                }
+            }
+
             /* Turn the pixbuf into a gtk_image */
             if(G_LIKELY(pixbuf)) {
                 image = gtk_image_new_from_pixbuf(pixbuf);
