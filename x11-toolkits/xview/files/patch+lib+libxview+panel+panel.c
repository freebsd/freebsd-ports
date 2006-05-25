--- lib/libxview/panel/panel.c.orig	Sat Mar 25 23:52:08 2006
+++ lib/libxview/panel/panel.c	Sun Mar 26 00:19:28 2006
@@ -27,6 +27,7 @@
 Pkg_private int panel_destroy();
 
 static int      panel_layout();
+static int	panel_unregister_view(Panel_info *panel, Xv_Window view);
 
 Xv_private_data Defaults_pairs xv_kbd_cmds_value_pairs[4];
 
