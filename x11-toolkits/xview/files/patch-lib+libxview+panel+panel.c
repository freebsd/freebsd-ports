--- ./lib/libxview/panel/panel.c.orig	Tue Jun 29 07:16:57 1993
+++ ./lib/libxview/panel/panel.c	Sat Apr  1 18:25:27 2000
@@ -27,6 +27,7 @@ Pkg_private int panel_view_init();
 Pkg_private int panel_destroy();
 
 static int      panel_layout();
+static int	panel_unregister_view();
 
 Xv_private_data Defaults_pairs xv_kbd_cmds_value_pairs[4];
 
