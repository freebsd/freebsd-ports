--- src/main.c.orig	2009-10-21 23:07:11.000000000 +0900
+++ src/main.c	2010-01-21 01:15:42.000000000 +0900
@@ -323,9 +323,13 @@
 #endif
 	/* React on WM (re)starts */
 	if (ev.atom == XInternAtom(tray_data.dpy, _NET_SUPPORTING_WM_CHECK, False)) {
+#ifdef DEBUG
 		ewmh_list_supported_atoms(tray_data.dpy);
+#endif
 		tray_set_wm_hints();
+#ifndef NO_NATIVE_KDE
 		kde_tray_update_fallback_mode(tray_data.dpy);
+#endif
 	}
 	/* React on _XEMBED_INFO changes of embedded icons
 	 * (currently used to track icon visibility status) */
