--- src/theme-parser.c.orig	Sat May 24 19:12:06 2003
+++ src/theme-parser.c	Sat May 24 19:12:43 2003
@@ -4261,7 +4261,7 @@
   GError *error;
   ParseInfo info;
   char *text;
-  int length;
+  gsize length;
   char *theme_file;
   char *theme_dir;
   MetaTheme *retval;
