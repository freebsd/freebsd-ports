--- winbutton.c.orig	2013-09-17 21:38:07.482238656 -0700
+++ winbutton.c	2013-09-17 21:58:24.411286317 -0700
@@ -100,7 +100,7 @@
 
 	if (winInfo->ignore) {
 	    FrameAllowEvents(cli, event->xbutton.time);
-	    return;
+	    return 0;
 	}
 
         switch (a) {
@@ -128,7 +128,7 @@
 
 	default:
 	    FrameAllowEvents(cli, event->xbutton.time);
-	    return;
+	    return 0;
         }
 }
 
@@ -152,7 +152,7 @@
 	FrameAllowEvents(cli, event->xbutton.time);
 
 	if (!AllButtonsUp(event))
-	    return;
+	    return 0;
 
         XUngrabPointer(dpy, CurrentTime);
 
@@ -165,7 +165,7 @@
 	}
 
         if (!in_windowmark(winInfo,x,y) || currentAction != ACTION_SELECT) {
-	    return;
+	    return 0;
         }
 
 	if (! winInfo->ignore) {
@@ -202,7 +202,7 @@
 	else gis = WinGI(winInfo,NORMAL_GINFO);
 
 	if (!event->xmotion.same_screen || currentAction != ACTION_SELECT)
-		return;
+		return 0;
 
         x = event->xmotion.x;
         y = event->xmotion.y;
