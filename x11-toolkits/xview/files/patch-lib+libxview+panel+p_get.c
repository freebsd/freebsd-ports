--- ./lib/libxview/panel/p_get.c.orig	Tue Jun 29 07:16:49 1993
+++ ./lib/libxview/panel/p_get.c	Sat Apr  1 18:25:26 2000
@@ -16,6 +16,7 @@ static char     sccsid[] = "@(#)p_get.c 
 #include <xview/scrollbar.h>
 
 static int      shrink_to_fit();
+static panel_shrink_margin();
 
 #define MAX_NEGATIVE_SHRINK 2000
 #define SHRINK_MARGIN       4
