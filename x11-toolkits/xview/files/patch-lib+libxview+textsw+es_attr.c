--- ./lib/libxview/textsw/es_attr.c.orig	Tue Jun 29 07:17:31 1993
+++ ./lib/libxview/textsw/es_attr.c	Sat Apr  1 18:25:28 2000
@@ -22,7 +22,7 @@ static char     sccsid[] = "@(#)es_attr.
 
 Pkg_private int
 #ifdef ANSI_FUNC_PROTO
-es_set(register Es_handle esh, ...)
+es_set(Es_handle esh, ...)
 #else
 es_set(esh, va_alist)
     register Es_handle esh;
