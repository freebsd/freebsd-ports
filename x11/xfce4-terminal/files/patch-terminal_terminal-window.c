--- terminal/terminal-window.c.orig	2017-07-05 22:57:57 UTC
+++ terminal/terminal-window.c
@@ -1879,6 +1879,10 @@ title_popover_close (GtkWidget      *pop
   /* close the dialog */
   gtk_widget_destroy (window->priv->title_popover);
   window->priv->title_popover = NULL;
+
+  /* focus the terminal: bug #13754 */
+  if (G_LIKELY (window->priv->active != NULL))
+    terminal_screen_focus (window->priv->active);
 }
 
 
