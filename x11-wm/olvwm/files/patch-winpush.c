--- winpush.c.orig	2013-09-17 21:38:07.482238656 -0700
+++ winpush.c	2013-09-17 22:10:26.340945247 -0700
@@ -103,7 +103,7 @@
 {
 	FrameAllowEvents(winInfo->core.client, event->xbutton.time);
 	if (!AllButtonsUp(event))
-	    return;
+	    return 0;
 
 	/*
 	 * If pushpinStateAfterPress equals the current pin state, we know 
@@ -131,9 +131,9 @@
 	Graphics_info	*gisNormal = WinGI(winInfo,NORMAL_GINFO);
 
 	if (!event->xmotion.same_screen)
-	    return;
+	    return 0;
 	if (currentAction != ACTION_SELECT && currentAction != ACTION_ADJUST)
-	    return;
+	    return 0;
 
         /* When the user moves the cursor off the pushpin
          * while s/he has the button down we should pull
