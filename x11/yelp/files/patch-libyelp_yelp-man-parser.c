--- libyelp/yelp-man-parser.c.orig	2016-07-10 15:09:15 UTC
+++ libyelp/yelp-man-parser.c
@@ -369,7 +369,7 @@ get_troff (gchar *path, GError **error)
 {
     gint ystdout;
     GError *err = NULL;
-    const gchar *argv[] = { "man", "-Z", "-Tutf8", "-EUTF-8", path, NULL };
+    const gchar *argv[] = { "%%LIBEXECDIR%%", "/yelp-groff", path, NULL };
     gchar **my_argv;
 
     /* g_strdupv() should accept a "const gchar **". */
