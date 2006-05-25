--- lib/libxview/io_stream/input.c.orig	Sat Mar 25 23:13:46 2006
+++ lib/libxview/io_stream/input.c	Sat Mar 25 23:14:17 2006
@@ -22,7 +22,7 @@
 		XV_MSG("input stream not of type input"), 0); \
 	ops = in->ops.input_ops
 
-char	*stream_getstring();
+static char	*stream_getstring();
 
 /* GENERIC INPUT FUNCTIONS */
 
