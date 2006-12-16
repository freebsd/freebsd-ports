--- libxklavier/xklavier_xmm.c.orig	Sat Dec 16 01:25:29 2006
+++ libxklavier/xklavier_xmm.c	Sat Dec 16 01:29:39 2006
@@ -107,7 +107,7 @@ xkl_xmm_find_switch_option(XklEngine * e
 	const XmmSwitchOption *rv = xkl_xmm_shortcut_get_current(engine);
 
 	if (rv != NULL) {
-		XmmShortcut *sc = rv->shortcuts;
+		const XmmShortcut *sc = rv->shortcuts;
 		while (sc->keysym != XK_VoidSymbol) {
 			if ((XKeysymToKeycode
 			     (xkl_engine_get_display(engine),
