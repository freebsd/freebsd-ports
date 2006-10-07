--- lib/libxview/textsw/ev_display.c.orig	Thu Oct  5 19:30:17 2006
+++ lib/libxview/textsw/ev_display.c	Thu Oct  5 19:32:21 2006
@@ -940,7 +940,7 @@
 	register int    i;
 	Es_index        pos, pos_to_remember;
 	Pkg_private void ev_lt_format();
-	static void     ev_swap_line_table();
+	void     ev_swap_line_table();
 
 	esbuf.esh = chain->esh;
 	esbuf.buf = buf;
