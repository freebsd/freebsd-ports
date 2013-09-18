--- props.c.orig	1997-11-08 17:18:50.000000000 -0800
+++ props.c	2013-09-17 23:33:43.311493251 -0700
@@ -718,7 +718,7 @@
     int         factory = !(int) xv_get(panel_item, PANEL_VALUE);
 
     if (factory == showing_factory)
-	return;
+	return 0;
 
     if (factory) {
 	if (!saved_defaults[0]) {
@@ -752,7 +752,7 @@
     int         width;
 
     if (panel_group[which_panel] == current_panel)
-	return;
+	return 0;
 
     /* Show requested panel */
     xv_set(current_panel, XV_SHOW, FALSE, NULL);
@@ -816,7 +816,7 @@
     else
     {
         strcpy(localepath, openwin_dir);
-        strcat(localepath, "/lib/locale/");
+        strcat(localepath, "/lib/X11/locale/C/");
         bindtextdomain("props", localepath);
     }
 
