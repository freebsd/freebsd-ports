--- src/Window.cc.orig	2005-10-18 08:01:41 UTC
+++ src/Window.cc
@@ -33,6 +33,8 @@
 #include "Workspace.hh"
 #include "blackbox.hh"
 
+#include <cstdlib>
+
 #include <Pen.hh>
 #include <PixmapCache.hh>
 #include <Unicode.hh>
@@ -3699,14 +3701,14 @@ void collisionAdjust(int *dx, int *dy, int x, int y,
              wtop = y,
           wbottom = y + height - 1,
   // left, right, top + bottom are for rect, douterleft = left border of rect
-       dinnerleft = abs(wleft - rect.left()),
-      dinnerright = abs(wright - rect.right()),
-        dinnertop = abs(wtop - rect.top()),
-     dinnerbottom = abs(wbottom - rect.bottom()),
-       douterleft = abs(wright - rect.left()),
-      douterright = abs(wleft - rect.right()),
-        doutertop = abs(wbottom - rect.top()),
-     douterbottom = abs(wtop - rect.bottom());
+       dinnerleft = std::abs(wleft - rect.left()),
+      dinnerright = std::abs(wright - rect.right()),
+        dinnertop = std::abs(wtop - rect.top()),
+     dinnerbottom = std::abs(wbottom - rect.bottom()),
+       douterleft = std::abs(wright - rect.left()),
+      douterright = std::abs(wleft - rect.right()),
+        doutertop = std::abs(wbottom - rect.top()),
+     douterbottom = std::abs(wtop - rect.bottom());
 
   if ((wtop <= rect.bottom() && wbottom >= rect.top())
       || doutertop <= snap_distance
@@ -3749,8 +3751,8 @@ void collisionAdjust(int *dx, int *dy, int x, int y,
     const int cwy = y + height / 2;
     const int crx = rect.x() + rect.width() / 2;
     const int cry = rect.y() + rect.height() / 2;
-    const int cdx = abs(cwx - crx);
-    const int cdy = abs(cwy - cry);
+    const int cdx = std::abs(cwx - crx);
+    const int cdy = std::abs(cwy - cry);
     if (cdx <= snap_distance)
       // snap to horizontal center
       *dx = x - (rect.x() + ((rect.width() - width) / 2));
@@ -3773,13 +3775,13 @@ void BlackboxWindow::snapAdjust(int *x, int *y) {
   if (edge_distance) {
     collisionAdjust(&dx, &dy, *x, *y, frame.rect.width(), frame.rect.height(),
                     _screen->availableArea(), edge_distance, true);
-    nx = (dx != init_dx && abs(dx) < abs(nx)) ? dx : nx; dx = init_dx;
-    ny = (dy != init_dy && abs(dy) < abs(ny)) ? dy : ny; dy = init_dy;
+    nx = (dx != init_dx && std::abs(dx) < std::abs(nx)) ? dx : nx; dx = init_dx;
+    ny = (dy != init_dy && std::abs(dy) < std::abs(ny)) ? dy : ny; dy = init_dy;
     if (!blackbox->resource().fullMaximization()) {
       collisionAdjust(&dx, &dy, *x, *y, frame.rect.width(), frame.rect.height(),
                       _screen->screenInfo().rect(), edge_distance);
-      nx = (dx != init_dx && abs(dx) < abs(nx)) ? dx : nx; dx = init_dx;
-      ny = (dy != init_dy && abs(dy) < abs(ny)) ? dy : ny; dy = init_dy;
+      nx = (dx != init_dx && std::abs(dx) < std::abs(nx)) ? dx : nx; dx = init_dx;
+      ny = (dy != init_dy && std::abs(dy) < std::abs(ny)) ? dy : ny; dy = init_dy;
     }
   }
   if (win_distance) {
@@ -3791,8 +3793,8 @@ void BlackboxWindow::snapAdjust(int *x, int *y) {
           win->workspace() == _screen->currentWorkspace()) {
         collisionAdjust(&dx, &dy, *x, *y, frame.rect.width(),
                         frame.rect.height(), win->frame.rect, win_distance);
-        nx = (dx != init_dx && abs(dx) < abs(nx)) ? dx : nx; dx = init_dx;
-        ny = (dy != init_dy && abs(dy) < abs(ny)) ? dy : ny; dy = init_dy;
+        nx = (dx != init_dx && std::abs(dx) < std::abs(nx)) ? dx : nx; dx = init_dx;
+        ny = (dy != init_dy && std::abs(dy) < std::abs(ny)) ? dy : ny; dy = init_dy;
       }
     }
   }
