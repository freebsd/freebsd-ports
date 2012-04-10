--- xascii.c.orig	1991-08-05 13:57:57.000000000 -0700
+++ xascii.c	2010-10-13 16:14:45.388101391 -0700
@@ -454,8 +454,7 @@
 	XtTranslateCoords (toplevel,
 			(Position) 0,
 			(Position) height/2,
-			&x, &y,
-			NULL);
+			&x, &y);
 
 	XtVaSetValues (pshell,
 			XtNx, x,
