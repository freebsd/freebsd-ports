--- src/event.c
+++ src/event.c
@@ -559,6 +559,10 @@
             wwin->flags.skip_next_animation = 1;
             wIconifyWindow(wwin);
         }
+        if (wwin->flags.fullscreen) {
+            wwin->flags.fullscreen = 0;
+            wFullscreenWindow(wwin);
+        }
         if (wwin->flags.hidden) {
             WApplication *wapp = wApplicationOf(wwin->main_window);
 
