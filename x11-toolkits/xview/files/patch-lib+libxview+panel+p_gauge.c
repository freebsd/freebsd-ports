--- ./lib/libxview/panel/p_gauge.c.orig	Tue Jun 29 07:17:04 1993
+++ ./lib/libxview/panel/p_gauge.c	Sat Apr  1 18:25:26 2000
@@ -47,6 +47,7 @@ static void	gauge_layout();
 /* Local functions */
 static void     paint_gauge();
 static void     update_rects();
+static int	etoi();
 
 static Panel_ops ops = {
     panel_default_handle_event,		/* handle_event() */
