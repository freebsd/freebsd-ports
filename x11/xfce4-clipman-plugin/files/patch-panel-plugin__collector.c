--- panel-plugin/collector.c.orig	2011-10-20 14:42:39.000000000 +0200
+++ panel-plugin/collector.c	2011-11-05 00:16:40.000000000 +0100
@@ -154,7 +154,7 @@
   gchar *text;
   static gchar *prev_text = NULL;
 
-  g_return_if_fail (GTK_IS_CLIPBOARD (collector->priv->default_clipboard) && GTK_IS_CLIPBOARD (collector->priv->primary_clipboard));
+  g_return_val_if_fail (GTK_IS_CLIPBOARD (collector->priv->default_clipboard) && GTK_IS_CLIPBOARD (collector->priv->primary_clipboard), FALSE);
 
   /* Postpone until the selection is done */
   gdk_window_get_pointer (NULL, NULL, NULL, &state);
