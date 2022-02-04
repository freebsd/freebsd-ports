--- src/draw.c.orig	2022-02-04 14:30:20 UTC
+++ src/draw.c
@@ -47,7 +47,7 @@ void draw_init(struct term_buf* buf)
 		+ (config.input_len + 1)
 		+ buf->labels_max_len;
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	buf->box_chars.left_up = 0x250c;
 	buf->box_chars.left_down = 0x2514;
 	buf->box_chars.right_up = 0x2510;
