--- ./lib/libxview/rect/rect_util.c.orig	Tue Jun 29 07:15:17 1993
+++ ./lib/libxview/rect/rect_util.c	Sat Apr  1 18:25:27 2000
@@ -16,6 +16,8 @@ static char     sccsid[] = "@(#)rect_uti
 
 #include <xview/rect.h>
 
+static int rect_nearest_edge();
+
 /*
  * Compute the distance from rect to (x, y). If (x, y) is in rect, zero is
  * returned. If x_used or y_used are non-zero, the projection point is
