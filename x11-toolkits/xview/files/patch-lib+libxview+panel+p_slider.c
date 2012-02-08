--- lib/libxview/panel/p_slider.c.orig	2012-02-03 17:01:53.259129212 -0800
+++ lib/libxview/panel/p_slider.c	2012-02-03 17:05:37.912629308 -0800
@@ -54,6 +54,8 @@
 static Panel_setting get_value();
 static void     paint_slider();
 static void     update_rects();
+static int	etoi();
+static int	itoe();
 
 static Panel_ops ops = {
     panel_default_handle_event,		/* handle_event() */
@@ -1377,7 +1379,7 @@
 /*
  * Convert external value (client units) to internal value (pixels).
  */
-static int
+int
 etoi_slider(dp, value)
     Slider_info    *dp;
     int             value;
