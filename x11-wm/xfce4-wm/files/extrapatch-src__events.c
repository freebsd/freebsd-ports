--- src/events.c.orig	Mon Apr  2 21:48:20 2007
+++ src/events.c	Tue Jun 19 06:49:58 2007
@@ -860,11 +860,11 @@
 
     if (ev->button == Button4)
     {
-        workspaceSwitch (screen_info, screen_info->current_ws - 1, NULL, TRUE, ev->time);
+        workspaceSwitch (screen_info, screen_info->current_ws + 1, NULL, TRUE, ev->time);
     }
     else if (ev->button == Button5)
     {
-        workspaceSwitch (screen_info, screen_info->current_ws + 1, NULL, TRUE, ev->time);
+        workspaceSwitch (screen_info, screen_info->current_ws - 1, NULL, TRUE, ev->time);
     }
 }
 
