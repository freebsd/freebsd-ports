--- ./lib/libxview/textsw/ei_text.c.orig	Tue Jun 29 07:17:37 1993
+++ ./lib/libxview/textsw/ei_text.c	Sat Apr  1 18:25:28 2000
@@ -121,6 +121,7 @@ static void	ei_plain_text_set_dummy_char
 #endif
 static struct ei_span_result ei_plain_text_span_of_group();
 static struct ei_process_result ei_plain_text_expand();
+static paint_batch();
 
 struct ei_ops   ei_plain_text_ops = {
     ei_plain_text_destroy,
