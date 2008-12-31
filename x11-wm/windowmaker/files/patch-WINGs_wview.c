diff -urbB ../WindowMaker-0.92.0/WINGs/wview.c ./WINGs/wview.c
--- ../WindowMaker-0.92.0/WINGs/wview.c	2004-10-27 19:41:04.000000000 -0700
+++ ./WINGs/wview.c	2008-12-14 19:59:05.000000000 -0800
@@ -450,6 +450,9 @@
 
     W_FreeViewXdndPart(view);
 
+    if (view->backColor)
+        WMReleaseColor(view->backColor);
+
     wfree(view);
 }
 
@@ -715,7 +718,8 @@
 {
     WMScreen *scr = W_VIEW_SCREEN(view);
     Window foo;
-    int x, y, topX, topY, bar;
+    int x, y, topX, topY;
+    unsigned int bar;
     WMView *topView;
 
     topView = view;
