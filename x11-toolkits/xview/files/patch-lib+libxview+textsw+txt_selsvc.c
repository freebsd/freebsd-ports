--- ./lib/libxview/textsw/txt_selsvc.c.orig	Sun Jun 26 03:05:23 1994
+++ ./lib/libxview/textsw/txt_selsvc.c	Sat Apr  1 18:25:29 2000
@@ -24,6 +24,8 @@ static char     sccsid[] = "@(#)txt_sels
 #include <stdlib.h>
 #endif /* SVR4 */
 
+static int textsw_should_ask_seln_svc();
+
 extern int      errno;
 
 Pkg_private Es_status es_copy();
