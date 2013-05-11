https://bugzilla.xfce.org/show_bug.cgi?id=8744

--- ./libxfce4kbd-private/xfce-shortcut-dialog.c.orig	2012-04-28 19:46:52.000000000 +0000
+++ ./libxfce4kbd-private/xfce-shortcut-dialog.c	2013-05-09 09:19:32.000000000 +0000
@@ -327,6 +327,8 @@
                                        &keyval, NULL, NULL, &consumed);
 
   /* Get the modifiers */
+  if ((modifiers & GDK_SHIFT_MASK) && (consumed & GDK_SHIFT_MASK))
+    consumed &= ~GDK_SHIFT_MASK;
   modifiers &= ~consumed;
   modifiers &= mod_mask;
 
