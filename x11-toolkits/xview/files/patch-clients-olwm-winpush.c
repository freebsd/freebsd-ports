--- clients/olwm/winpush.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/winpush.c	2013-09-17 23:10:09.212267675 -0700
@@ -100,7 +100,7 @@
 {
 	FrameAllowEvents(winInfo->core.client, event->xbutton.time);
 	if (!AllButtonsUp(event))
-	    return;
+	    return 0;
 
 	/*
 	 * If pushpinStateAfterPress equals the current pin state, we know 
@@ -128,9 +128,9 @@
 	Graphics_info	*gisNormal = WinGI(winInfo,NORMAL_GINFO);
 
 	if (!event->xmotion.same_screen)
-	    return;
+	    return 0;
 	if (currentAction != ACTION_SELECT && currentAction != ACTION_ADJUST)
-	    return;
+	    return 0;
 
         /* When the user moves the cursor off the pushpin
          * while s/he has the button down we should pull
