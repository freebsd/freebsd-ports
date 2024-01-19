imlib_strerror is provided by Imlib2

--- src/pixmap.c.orig	2011-03-16 06:09:23 UTC
+++ src/pixmap.c
@@ -171,6 +171,7 @@ image_mode_any(unsigned char mode)
 }
 
 #ifdef PIXMAP_SUPPORT
+#if 0
 const char *
 imlib_strerror(Imlib_Load_Error err)
 {
@@ -224,6 +225,7 @@ imlib_strerror(Imlib_Load_Error err)
     }
     ASSERT_NOTREACHED_RVAL("");
 }
+#endif
 
 unsigned short
 parse_pixmap_ops(char *str)
@@ -1916,7 +1918,8 @@ update_desktop_info(int *w, int *h)
     }
     if (desktop_window == None) {
         libast_print_error("Unable to locate desktop window.  If you are running Enlightenment, please\n"
-                    "restart.  If not, please set your background image with Esetroot, then try again.");
+                    "restart.  If not, please set your background image with Esetroot, then try again.\n"
+		    "Or, if you are running Enlightenment DR17, use e17setroot.");
         return 0;
     }
     if (desktop_pixmap == None) {
