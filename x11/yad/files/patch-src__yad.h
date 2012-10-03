--- ../yad-0.17.1.1-a/src/yad.h        2012-02-28 07:09:00.000000000 -0300
+++ src/yad.h  2012-10-01 17:09:46.007019884 -0300
@@ -395,7 +395,7 @@
 
 GdkPixbuf * get_pixbuf (gchar *name, YadIconSize size);
 
-inline void strip_new_line (gchar *str);
+void strip_new_line (gchar *str);
 gchar **split_arg (const gchar *str);
 
 char *escape_markup (char *str);
