--- wingframe.c.orig	2013-09-17 21:38:07.442239399 -0700
+++ wingframe.c	2013-09-17 22:01:51.492024906 -0700
@@ -285,7 +285,7 @@
         Client *cli = frameInfo->core.client;
 
 	if (!AllButtonsUp(event))
-	    return;
+	    return 0;
 
 #define bevent  (event->xbutton)
 
@@ -353,16 +353,16 @@
         /* We get this only after a Select press */
         if (hadSelect == False) /* watch for erroneous motions */
         {
-                return;
+                return 0;
         }
 
 	if (!event->xmotion.same_screen)
-		return;
+		return 0;
 
         /* See if we have moved more than the threshold amount. */
         if ((ABS(event->xmotion.x - buttonPressX) < GRV.MoveThreshold) &&
             (ABS(event->xmotion.y - buttonPressY) < GRV.MoveThreshold))
-                return;
+                return 0;
 
 	(WinFunc(frameInfo,fcore.selectDrag))(dpy, event, frameInfo, &lastSelectPress);
 
