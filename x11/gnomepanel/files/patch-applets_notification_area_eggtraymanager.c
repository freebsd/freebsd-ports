--- applets/notification_area/eggtraymanager.c.orig	Wed Feb 12 20:37:06 2003
+++ applets/notification_area/eggtraymanager.c	Wed Feb 12 20:37:35 2003
@@ -399,7 +399,7 @@
 
   invisible = manager->invisible;
   
-  display = GDK_WINDOW_XDISPLAY (manager->invisible);
+  display = GDK_WINDOW_XDISPLAY (manager->invisible->window);
   
   if (XGetSelectionOwner (display, manager->selection_atom) ==
       GDK_WINDOW_XWINDOW (manager->invisible->window))
