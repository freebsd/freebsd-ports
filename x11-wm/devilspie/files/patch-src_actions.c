--- src/actions.c.orig	Fri Oct 21 11:58:14 2005
+++ src/actions.c	Tue Jan 24 18:30:58 2006
@@ -138,14 +138,14 @@
   gint xoffset, yoffset, window_width, window_height,
     workspace_width, workspace_height;
   int new_xoffset, new_yoffset;
+  WnckScreen *screen;
+  WnckWorkspace *workspace;
 
   /* read in window geometry */
   wnck_window_get_geometry (c->window,
                             &xoffset, &yoffset, &window_width, &window_height);
 
   /* read in workspace geometry */
-  WnckScreen *screen;
-  WnckWorkspace *workspace;
   screen           = wnck_window_get_screen (c->window);
   workspace        = wnck_screen_get_active_workspace (screen);
   workspace_width  = wnck_workspace_get_width  (workspace);
