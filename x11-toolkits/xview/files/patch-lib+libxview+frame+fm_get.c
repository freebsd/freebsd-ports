--- ./lib/libxview/frame/fm_get.c.orig	Tue Jun 29 07:16:10 1993
+++ ./lib/libxview/frame/fm_get.c	Sat Apr  1 18:25:24 2000
@@ -10,6 +10,7 @@ static char     sccsid[] = "@(#)fm_get.c
  *	file for terms of the license.
  */
 
+#include <ctype.h>
 #include <xview_private/fm_impl.h>
 #include <xview_private/draw_impl.h>
 #include <xview/server.h>
