--- clients/olwm/winpane.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/winpane.c	2013-09-17 23:07:20.091766948 -0700
@@ -162,7 +162,7 @@
 	/* it's a ShapeNotify event */
 	se = (XShapeEvent *) event;
 	if (se->kind != ShapeBounding)
-	    return;
+	    return 0;
 	cli = winInfo->core.client;
 	cli->isShaped = se->shaped;
 	
