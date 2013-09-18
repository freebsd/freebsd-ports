--- clients/olwm/wingframe.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/wingframe.c	2013-09-17 23:03:37.471110388 -0700
@@ -270,7 +270,7 @@
         Client *cli = frameInfo->core.client;
 
 	if (!AllButtonsUp(event))
-	    return;
+	    return 0;
 
 #define bevent  (event->xbutton)
 
@@ -337,16 +337,16 @@
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
 
