--- winframe.c.orig	2013-09-17 21:38:07.462238988 -0700
+++ winframe.c	2013-09-17 22:00:01.011629533 -0700
@@ -52,6 +52,8 @@
 
 extern Time TimeFresh();
 
+static headerHeight();
+
 /***************************************************************************
 * private data
 ***************************************************************************/
@@ -493,7 +495,7 @@
 {
     /* ignore events caused by grabs */
     if (event->xcrossing.mode != NotifyNormal)
-	return;
+	return 0;
 
     if (event->xcrossing.detail != NotifyInferior)
 	frameInfo->pointerIsWarped = False;
