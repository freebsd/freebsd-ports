--- winresize.c.orig	2013-09-17 21:38:07.392239520 -0700
+++ winresize.c	2013-09-17 22:11:21.781075811 -0700
@@ -81,7 +81,7 @@
 
         if (ResolveMouseBinding(dpy, event, ignoremask) != ACTION_SELECT) {
 	    FrameAllowEvents(winInfo->core.client, event->xbutton.time);
-	    return;
+	    return 0;
 	}
 
 	/* draw depressed corner */
