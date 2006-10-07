--- lib/libxview/panel/item_set.c.orig	Thu Oct  5 19:03:02 2006
+++ lib/libxview/panel/item_set.c	Thu Oct  5 19:04:55 2006
@@ -26,6 +26,8 @@
 
 static void item_adjust_label_size();
 
+static fix_positions();
+
 extern Notify_value panel_base_event_handler();
 
 Pkg_private     Xv_opaque
