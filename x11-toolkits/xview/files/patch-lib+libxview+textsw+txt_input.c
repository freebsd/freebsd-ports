--- ./lib/libxview/textsw/txt_input.c.orig	Tue Jun 29 07:17:42 1993
+++ ./lib/libxview/textsw/txt_input.c	Sat Apr  1 18:25:29 2000
@@ -57,6 +57,8 @@ static	void	textsw_do_undo();
 Pkg_private     void textsw_implicit_commit_doit();
 #endif
 
+static int textsw_do_newline();
+
 #define SPACE_CHAR 0x20
 
 Pkg_private int
