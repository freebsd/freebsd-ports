--- ./lib/libxview/textsw/ps_impl.c.orig	Tue Jun 29 07:17:39 1993
+++ ./lib/libxview/textsw/ps_impl.c	Sat Apr  1 18:25:29 2000
@@ -62,6 +62,10 @@ static Es_index ps_read(), ps_scratch_re
 static Es_index ps_replace(), ps_scratch_replace();
 static int      ps_set();
 
+static int	get_current_offset();
+
+static copy_pieces();
+
 static Es_index write_header_etc();
 
 static struct es_ops ps_ops = {
