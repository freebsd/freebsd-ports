--- src/EventHandler.cc.orig	Mon Jun 17 19:14:12 2002
+++ src/EventHandler.cc	Mon Jun 17 19:38:20 2002
@@ -94,7 +94,7 @@
 void EventHandler::HandleEvent(XEvent *event) {
     Window w;
     int i, rx, ry;
-    struct timeb click_time;
+    struct timeval click_time;
     
     EventDetail *ed = new EventDetail;
 
@@ -136,36 +136,36 @@
         case ButtonPress:
             ed->type = ButtonPress;
             if (last_click_win == event->xbutton.window) {
-                ftime(&click_time);
-                if (click_time.time <= last_click.time + 1) {
-                    if (click_time.time == last_click.time &&
+                gettimeofday(&click_time, NULL);
+                if (click_time.tv_sec <= last_click.tv_sec + 1) {
+                    if (click_time.tv_sec == last_click.tv_sec &&
                         (unsigned int)
-                        (click_time.millitm - last_click.millitm) <
-                        waimea->rh->double_click) {
+                        (click_time.tv_usec - last_click.tv_usec)
+                        / 1000 < waimea->rh->double_click) {
                         ed->type = DoubleClick;
                         last_click_win = (Window) 0;
                     }
-                    else if ((1000 - last_click.millitm) +
-                             (unsigned int) click_time.millitm <
-                             waimea->rh->double_click) {
+                    else if (((1000000 - last_click.tv_usec) +
+                             (unsigned int) click_time.tv_usec)
+                             / 1000 < waimea->rh->double_click) {
                         ed->type = DoubleClick;
                             last_click_win = (Window) 0;
                     }
                     else {
                         last_click_win = event->xbutton.window;
-                        last_click.time = click_time.time;
-                        last_click.millitm = click_time.millitm;
+                        last_click.tv_sec = click_time.tv_sec;
+                        last_click.tv_usec = click_time.tv_usec;
                     }
                 }
                 else {
                     last_click_win = event->xbutton.window;
-                    last_click.time = click_time.time;
-                    last_click.millitm = click_time.millitm;
+                    last_click.tv_sec = click_time.tv_sec;
+                    last_click.tv_usec = click_time.tv_usec;
                 }
             }
             else {
                 last_click_win = event->xbutton.window;
-                ftime(&last_click);
+                gettimeofday(&last_click, NULL);
             }
         case ButtonRelease:
             if (event->type == ButtonRelease) ed->type = ButtonRelease;
