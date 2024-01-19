imlib_strerror is provided by Imlib2

--- src/pixmap.h.orig	2009-01-06 09:05:36 UTC
+++ src/pixmap.h
@@ -221,7 +221,6 @@ extern unsigned char image_mode_any(unsigned char);
 extern const char *get_image_type(unsigned char);
 extern unsigned char image_mode_any(unsigned char);
 #ifdef PIXMAP_SUPPORT
-extern const char *imlib_strerror(Imlib_Load_Error);
 extern unsigned short parse_pixmap_ops(char *);
 extern unsigned short set_pixmap_scale(const char *, pixmap_t *);
 extern unsigned char check_image_ipc(unsigned char);
