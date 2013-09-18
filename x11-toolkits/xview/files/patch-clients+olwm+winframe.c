--- clients/olwm/winframe.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/winframe.c	2013-09-17 23:01:57.600816158 -0700
@@ -29,6 +29,7 @@
 #include "globals.h"
 #include "error.h"
 
+static int headerHeight(Client *cli, Graphics_info *gis);
 
 /***************************************************************************
 * global data
@@ -461,7 +462,7 @@
 {
     /* ignore events caused by grabs */
     if (event->xcrossing.mode != NotifyNormal)
-	return;
+	return 0;
 
     if (event->xcrossing.detail != NotifyInferior)
 	frameInfo->pointerIsWarped = False;
