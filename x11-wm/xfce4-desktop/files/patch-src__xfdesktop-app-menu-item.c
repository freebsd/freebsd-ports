--- ./src/xfdesktop-app-menu-item.c.orig	2013-09-16 07:17:42.000000000 +0000
+++ ./src/xfdesktop-app-menu-item.c	2013-12-17 20:23:34.000000000 +0000
@@ -31,6 +31,7 @@
 
 #include <libxfce4util/libxfce4util.h>
 #include <libxfce4ui/libxfce4ui.h>
+#include <exo/exo.h>
 
 #include "xfdesktop-app-menu-item.h"
 
@@ -212,6 +213,11 @@
 
             /* Turn the pixbuf into a gtk_image */
             if(G_LIKELY(pixbuf)) {
+                /* scale the pixbuf down if it needs it */
+                GdkPixbuf *tmp = exo_gdk_pixbuf_scale_down(pixbuf, TRUE, w, h);
+                g_object_unref(pixbuf);
+                pixbuf = tmp;
+
                 image = gtk_image_new_from_pixbuf(pixbuf);
                 g_object_unref(G_OBJECT(pixbuf));
             }
