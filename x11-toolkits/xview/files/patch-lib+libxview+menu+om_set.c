--- ./lib/libxview/menu/om_set.c.orig	Tue Jun 29 07:16:24 1993
+++ ./lib/libxview/menu/om_set.c	Sat Apr  1 18:25:25 2000
@@ -12,6 +12,7 @@ static char     sccsid[] = "@(#)om_set.c
 
 /* --------------------------------------------------------------------- */
 #include <sys/types.h>
+#include <ctype.h>
 #include <xview_private/om_impl.h>
 #include <xview_private/draw_impl.h>
 #include <xview_private/fm_impl.h>
