--- ./lib/libxview/panel/p_drop.c.orig	Tue Jun 29 07:17:04 1993
+++ ./lib/libxview/panel/p_drop.c	Sat Apr  1 18:25:26 2000
@@ -10,7 +10,12 @@ static char     sccsid[] = "@(#)p_drop.c
  *	file for terms of the license.
  */
 
+#include <sys/param.h>
+#if (defined(BSD) && (BSD >= 199103))
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <xview_private/draw_impl.h>
 #include <xview_private/i18n_impl.h>
 #include <xview_private/panel_impl.h>
