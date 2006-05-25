--- lib/libxview/textsw/txt_getkey.c.orig	2006-01-04 11:41:31.000000000 +0000
+++ lib/libxview/textsw/txt_getkey.c
@@ -21,8 +21,6 @@ static char     sccsid[] = "@(#)txt_getk
 #include <xview_private/ev_impl.h>	/* For declaration of ev_add_finder */
 #include <errno.h>
 
-extern int      errno;
-
 static void     textsw_do_get();
 Pkg_private Es_index textsw_find_mark_internal();
 Pkg_private Es_index textsw_insert_pieces();
