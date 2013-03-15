--- src/vte.c.orig	2010-11-13 06:18:41.000000000 -0600
+++ src/vte.c	2013-03-14 15:59:37.761401135 -0500
@@ -4914,16 +4914,23 @@
 vte_terminal_read_modifiers (VteTerminal *terminal,
 			     GdkEvent    *event)
 {
+	GdkKeymap *keymap;
 	GdkModifierType modifiers;
 
 	/* Read the modifiers. */
-	if (gdk_event_get_state((GdkEvent*)event, &modifiers)) {
-		GdkKeymap *keymap;
-		keymap = gdk_keymap_get_for_display (
-				gdk_drawable_get_display (((GdkEventAny *)event)->window));
-		gdk_keymap_add_virtual_modifiers (keymap, &modifiers);
-		terminal->pvt->modifiers = modifiers;
-	}
+	if (!gdk_event_get_state((GdkEvent*)event, &modifiers))
+		return;
+
+	keymap = gdk_keymap_get_for_display (
+			gdk_window_get_display (((GdkEventAny*)event)->window));
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
