--- src/devilspie-action-resize.c.orig	Wed Mar 16 03:24:03 2005
+++ src/devilspie-action-resize.c	Wed Mar 16 03:24:58 2005
@@ -342,7 +342,7 @@
     if (a->minimized == TRI_TRUE)
       wnck_window_minimize(window);
     else if (a->minimized == TRI_FALSE)
-      wnck_window_unminimize(window);
+      wnck_window_unminimize(window, 0);
     /* Handle full screen */
     if (a->fullscreen != TRI_UNSET) {
         g_print("fullscreen\n");
