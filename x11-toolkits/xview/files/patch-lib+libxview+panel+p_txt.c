--- ./lib/libxview/panel/p_txt.c.orig	Tue Jun 29 07:16:55 1993
+++ ./lib/libxview/panel/p_txt.c	Sat Apr  1 18:25:27 2000
@@ -10,7 +10,12 @@ static char     sccsid[] = "@(#)p_txt.c 
  *	file for terms of the license.
  */
 
+#include <sys/param.h>
+#if (defined(BSD) && (BSD >= 199103))
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <ctype.h>
 #include <X11/X.h>
