https://bugzilla.xfce.org/show_bug.cgi?id=8744

--- ./libxfce4kbd-private/xfce-shortcuts-grabber.c.orig	2012-04-28 19:46:52.000000000 +0000
+++ ./libxfce4kbd-private/xfce-shortcuts-grabber.c	2013-05-09 09:25:50.000000000 +0000
@@ -512,8 +512,10 @@
                                        &keyval, NULL, NULL, &consumed);
 
   /* Get the modifiers */
-  modifiers &= ~consumed;
+  if ((modifiers & GDK_SHIFT_MASK) && (consumed & GDK_SHIFT_MASK))
+    consumed &= ~GDK_SHIFT_MASK;
   gdk_keymap_add_virtual_modifiers (keymap, &modifiers);
+  modifiers &= ~consumed;
   modifiers &= mod_mask;
 
   context.keyval = keyval;
@@ -521,6 +523,7 @@
 
   raw_shortcut_name = gtk_accelerator_name (keyval, modifiers);
   TRACE ("Looking for %s", raw_shortcut_name);
+  gtk_accelerator_parse (raw_shortcut_name, &context.keyval, &context.modifiers);
   g_free (raw_shortcut_name);
 
   g_hash_table_foreach (grabber->priv->keys, (GHFunc) find_event_key, &context);
