--- src/vte.c.orig	2011-08-28 23:31:45.000000000 +0200
+++ src/vte.c	2014-02-11 21:57:19.000000000 +0100
@@ -5164,19 +5164,23 @@
 vte_terminal_read_modifiers (VteTerminal *terminal,
 			     GdkEvent *event)
 {
+	GdkKeymap *keymap;
 	GdkModifierType modifiers;
 
 	/* Read the modifiers. */
-	if (gdk_event_get_state((GdkEvent*)event, &modifiers)) {
-		GdkKeymap *keymap;
-#if GTK_CHECK_VERSION (2, 90, 8)
-                keymap = gdk_keymap_get_for_display(gdk_window_get_display(((GdkEventAny*)event)->window));
-#else
-                keymap = gdk_keymap_get_for_display(gdk_drawable_get_display(((GdkEventAny*)event)->window));
-#endif
-                gdk_keymap_add_virtual_modifiers (keymap, &modifiers);
-		terminal->pvt->modifiers = modifiers;
-	}
+	if (!gdk_event_get_state((GdkEvent*)event, &modifiers))
+		return;
+
+	keymap = gdk_keymap_get_for_display (
+		gdk_window_get_display (((GdkEventAny*)event)->window));
+
+	gdk_keymap_add_virtual_modifiers (keymap, &modifiers);
+
+	/* HACK! Treat ALT as META; see bug #663779. */
+	if (modifiers & GDK_MOD1_MASK)
+		modifiers |= VTE_META_MASK;
+
+	terminal->pvt->modifiers = modifiers;
 }
 
 /* Read and handle a keypress event. */
