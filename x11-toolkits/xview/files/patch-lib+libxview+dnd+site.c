--- ./lib/libxview/dnd/site.c.orig	Tue Jun 29 07:15:58 1993
+++ ./lib/libxview/dnd/site.c	Sat Apr  1 18:25:23 2000
@@ -19,6 +19,7 @@ static char     sccsid[] = "@(#)site.c 1
 #ifdef SVR4 
 #include <stdlib.h> 
 #endif SVR4
+#include <sys/param.h>
 
 static     void 	TransCoords();
 Xv_private Xv_Window	win_get_top_level();
@@ -246,7 +247,11 @@ DndDropAreaOps(site, mode, area)
           /* (rectNode->rect) is of the wrong type. */
           memmove(rect, &(rectNode->rect),  sizeof(Rect));
 #else
+#if (defined(BSD) && (BSD >= 199103))
+	  bcopy(&(rectNode->rect), rect, sizeof(Rect));
+#else
 	  bcopy(rectNode->rect, rect, sizeof(Rect));
+#endif
 #endif SVR4
 
 	  return((Xv_opaque)rect);
