--- ./lib/libxview/panel/p_slider.c.orig	Tue Jun 29 07:17:02 1993
+++ ./lib/libxview/panel/p_slider.c	Sat Apr  1 18:25:27 2000
@@ -54,6 +54,8 @@ static void	check_endbox_entered();
 static Panel_setting get_value();
 static void     paint_slider();
 static void     update_rects();
+static int	etoi();
+static int	itoe();
 
 static Panel_ops ops = {
     panel_default_handle_event,		/* handle_event() */
