--- driver/demo-Gtk.c.orig	Wed Sep  3 19:02:03 2003
+++ driver/demo-Gtk.c	Tue Sep  9 03:14:32 2003
@@ -4540,9 +4540,11 @@
   free (window_title);
   window_title = 0;
 
+#if 0
   /* After picking the default size, allow -geometry to override it. */
   if (geom)
     gtk_window_parse_geometry (GTK_WINDOW (s->toplevel_widget), geom);
+#endif
 
   gtk_widget_show (s->toplevel_widget);
   init_icon (GTK_WIDGET (s->toplevel_widget)->window);  /* after `show' */
