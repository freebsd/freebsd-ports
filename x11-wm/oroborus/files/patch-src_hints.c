--- src/hints.c.orig	2006-01-12 15:40:43 UTC
+++ src/hints.c
@@ -43,7 +43,7 @@ Atom win_hints, win_state, win_client_list, win_layer,
   win_workspace_count, win_desktop_button_proxy, win_supporting_wm_check,
   gnome_panel_desktop_area;
 Atom net_atoms[NET_ATOM_COUNT];
-Display *dpy;
+extern Display *dpy;
 
 void
 initHints (Display * d)
