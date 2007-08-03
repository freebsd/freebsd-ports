--- clients/olwm/winframe.c.orig	2007-08-03 15:14:08.000000000 +0200
+++ clients/olwm/winframe.c	2007-08-03 15:15:06.000000000 +0200
@@ -29,6 +29,7 @@
 #include "globals.h"
 #include "error.h"
 
+static int headerHeight(Client *cli, Graphics_info *gis);
 
 /***************************************************************************
 * global data
