--- ./lib/libxview/panel/p_set.c.orig	Tue Jun 29 07:16:59 1993
+++ ./lib/libxview/panel/p_set.c	Sat Apr  1 18:25:27 2000
@@ -25,6 +25,8 @@ Xv_private char     *xv_font_regular_cmd
 
 static void panel_set_fonts();
 
+static int column_from_absolute_x();
+static int row_from_absolute_y();
 
 Pkg_private     Xv_opaque
 panel_set_avlist(panel_public, avlist)
