--- clients/olwm/winresize.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/winresize.c	2013-09-17 23:11:13.342458132 -0700
@@ -78,7 +78,7 @@
 
         if (ResolveMouseBinding(dpy, event, ignoremask) != ACTION_SELECT) {
 	    FrameAllowEvents(winInfo->core.client, event->xbutton.time);
-	    return;
+	    return 0;
 	}
 
 	/* draw depressed corner */
