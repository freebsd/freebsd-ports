--- ./lib/libxview/textsw/txt_putkey.c.orig	Tue Jun 29 07:17:41 1993
+++ ./lib/libxview/textsw/txt_putkey.c	Sat Apr  1 18:25:29 2000
@@ -21,6 +21,8 @@ static char     sccsid[] = "@(#)txt_putk
 
 extern int      errno;
 
+static int	textsw_do_put();
+
 Pkg_private Ev_finger_handle ev_add_finger();
 Pkg_private int      ev_get_selection();
 Pkg_private Es_handle textsw_esh_for_span();
