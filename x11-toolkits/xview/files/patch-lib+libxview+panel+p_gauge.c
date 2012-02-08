--- lib/libxview/panel/p_gauge.c.orig	2012-02-03 17:06:18.363199423 -0800
+++ lib/libxview/panel/p_gauge.c	2012-02-03 17:08:58.565678508 -0800
@@ -47,6 +47,7 @@
 /* Local functions */
 static void     paint_gauge();
 static void     update_rects();
+static int	etoi();
 
 static Panel_ops ops = {
     panel_default_handle_event,		/* handle_event() */
@@ -535,7 +536,7 @@
 /*
  * Convert external value (client units) to internal value (pixels).
  */
-static int
+int
 etoi_gauge(dp, value)
     Gauge_info    *dp;
     int             value;
