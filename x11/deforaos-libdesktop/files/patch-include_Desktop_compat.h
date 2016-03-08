--- include/Desktop/compat.h.orig	2016-03-06 06:55:36 UTC
+++ include/Desktop/compat.h
@@ -103,7 +103,7 @@
 # endif
 
 /* Gtk+ 3.0 */
-# if GTK_CHECK_VERSION(3, 0, 0)
+# if !GTK_CHECK_VERSION(3, 0, 0)
 void gdk_window_clear(GdkWindow * window);
 
 GtkWidget * gtk_box_new(GtkOrientation orientation, gint spacing);
