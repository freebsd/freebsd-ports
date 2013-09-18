--- clients/props/props.c.orig	2005-03-28 06:39:19.000000000 -0800
+++ clients/props/props.c	2013-09-17 23:14:50.153104437 -0700
@@ -717,7 +717,7 @@
     int         factory = !(int) xv_get(panel_item, PANEL_VALUE);
 
     if (factory == showing_factory)
-	return;
+	return 0;
 
     if (factory) {
 	if (!saved_defaults[0]) {
@@ -751,7 +751,7 @@
     int         width;
 
     if (panel_group[which_panel] == current_panel)
-	return;
+	return 0;
 
     /* Show requested panel */
     xv_set(current_panel, XV_SHOW, FALSE, NULL);
