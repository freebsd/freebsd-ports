--- ./lib/libxview/ttysw/cim_size.c.orig	Tue Jun 29 07:17:14 1993
+++ ./lib/libxview/ttysw/cim_size.c	Sat Apr  1 18:25:33 2000
@@ -156,19 +156,19 @@ xv_tty_free_image_and_mode()
 {
 
     if (lines_ptr) {
-        cfree((CHAR *) (lines_ptr));
+        free((CHAR *) (lines_ptr));
 	lines_ptr = NULL;
     }
     if (image) {
-        cfree((CHAR **) image);
+        free((CHAR **) image);
 	image = NULL;
     }
     if (mode_ptr) {
-	cfree((char *) (mode_ptr));
+	free((char *) (mode_ptr));
 	mode_ptr = NULL;
     }
     if (screenmode) {
-	cfree((char **) screenmode);
+	free((char **) screenmode);
 	screenmode = NULL;
     }
 }
