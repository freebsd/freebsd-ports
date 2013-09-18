--- winpane.c.orig	2013-09-17 21:38:07.492238885 -0700
+++ winpane.c	2013-09-17 22:07:33.003048309 -0700
@@ -171,7 +171,7 @@
 	/* it's a ShapeNotify event */
 	se = (XShapeEvent *) event;
 	if (se->kind != ShapeBounding)
-	    return;
+	    return 0;
 	cli = winInfo->core.client;
 	cli->isShaped = se->shaped;
 	
