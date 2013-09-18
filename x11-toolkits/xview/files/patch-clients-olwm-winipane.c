--- clients/olwm/winipane.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/winipane.c	2013-09-17 23:04:46.971315127 -0700
@@ -70,7 +70,7 @@
     XGCValues gcv;
 
     if (winInfo->iconClientWindow)
-	return;
+	return 0;
 
     XFillRectangle(dpy, pane, WinGC(winInfo,WORKSPACE_GC),
 		0, 0, winInfo->core.width, winInfo->core.height);
