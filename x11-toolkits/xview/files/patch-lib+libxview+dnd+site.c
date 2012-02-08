--- lib/libxview/dnd/site.c.orig	2005-03-28 06:41:43.000000000 -0800
+++ lib/libxview/dnd/site.c	2012-02-02 16:53:57.650628403 -0800
@@ -19,6 +19,7 @@
 #ifdef SVR4 
 #include <stdlib.h> 
 #endif /* SVR4 */
+#include <sys/param.h>
 
 static     void 	TransCoords();
 Xv_private Xv_Window	win_get_top_level();
@@ -245,6 +246,8 @@
           /* This will probably not work right, but it compiles. */
           /* (rectNode->rect) is of the wrong type. */
           memmove(rect, &(rectNode->rect),  sizeof(Rect));
+#elif (defined(BSD) && (BSD >= 199103))
+	  bcopy(&(rectNode->rect), rect, sizeof(Rect));
 #else
 	  bcopy(rectNode->rect, rect, sizeof(Rect));
 #endif /* SVR4 */
