--- gtk/window-decorator/gtk-window-decorator.c.orig	2010-04-06 18:29:25.000000000 +0200
+++ gtk/window-decorator/gtk-window-decorator.c	2010-04-06 18:40:04.000000000 +0200
@@ -4233,7 +4233,7 @@ show_tooltip (const char *text)
 static void
 hide_tooltip (void)
 {
-    if (GTK_WIDGET_VISIBLE (tip_window))
+    if (gtk_widget_get_visible (tip_window))
 	g_get_current_time (&tooltip_last_popdown);
 
     gtk_widget_hide (tip_window);
