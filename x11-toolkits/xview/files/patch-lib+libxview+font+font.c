--- ./lib/libxview/font/font.c.orig	Tue Jun 29 07:15:01 1993
+++ ./lib/libxview/font/font.c	Sat Apr  1 18:25:24 2000
@@ -67,6 +67,10 @@ Xv_private char *xv_font_regular_cmdline
 Xv_private char *xv_font_scale_cmdline();
 Xv_private char *xv_font_scale();
 
+static int font_setup_defaults();
+static int font_construct_name();
+static int font_init_create_attrs();
+
 /*
  * delimiters
  */
