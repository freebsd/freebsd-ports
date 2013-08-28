--- cursor/cursor.h.orig	2013-08-28 13:57:29.231213533 +0200
+++ cursor/cursor.h	2013-08-28 13:57:38.222207468 +0200
@@ -154,7 +154,7 @@
 } __attribute__((packed)) xcint_image_t;
 
 /* shape_to_id.c */
-const int cursor_shape_to_id(const char *name);
+int cursor_shape_to_id(const char *name);
 
 /* parse_cursor_file.c */
 int parse_cursor_file(xcb_cursor_context_t *c, const int fd, xcint_image_t **images, int *nimg);
