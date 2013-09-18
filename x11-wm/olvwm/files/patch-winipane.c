--- winipane.c.orig	2013-09-17 21:38:07.432239206 -0700
+++ winipane.c	2013-09-17 22:03:24.772361669 -0700
@@ -95,7 +95,7 @@
 	    XSetBackground(dpy, gc,
 			   winInfo->core.client->scrInfo->colorInfo.bgColor);
 	}
-	return;
+	return 0;
     }
 
     XFillRectangle(dpy, pane, WinGC(winInfo,WORKSPACE_GC),
