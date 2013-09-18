--- clients/olwm/winbutton.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/winbutton.c	2013-09-17 23:00:34.703056428 -0700
@@ -89,7 +89,7 @@
 
 	if (winInfo->ignore) {
 	    FrameAllowEvents(cli, event->xbutton.time);
-	    return;
+	    return 0;
 	}
 
         switch (a) {
@@ -117,7 +117,7 @@
 
 	default:
 	    FrameAllowEvents(cli, event->xbutton.time);
-	    return;
+	    return 0;
         }
 }
 
@@ -141,7 +141,7 @@
 	FrameAllowEvents(cli, event->xbutton.time);
 
 	if (!AllButtonsUp(event))
-	    return;
+	    return 0;
 
         XUngrabPointer(dpy, CurrentTime);
 
@@ -154,7 +154,7 @@
 	}
 
         if (!in_windowmark(winInfo,x,y) || currentAction != ACTION_SELECT) {
-	    return;
+	    return 0;
         }
 
 	if (! winInfo->ignore) {
@@ -186,7 +186,7 @@
 	Graphics_info	*gisNormal = WinGI(winInfo,NORMAL_GINFO);
 
 	if (!event->xmotion.same_screen || currentAction != ACTION_SELECT)
-		return;
+		return 0;
 
         x = event->xmotion.x;
         y = event->xmotion.y;
