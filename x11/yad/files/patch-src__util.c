--- ../yad-0.17.1.1-a/src/util.c       2012-02-28 07:18:06.000000000 -0300
+++ src/util.c 2012-10-01 17:09:25.640983063 -0300
@@ -187,7 +187,7 @@
   return pb;
 }
 
-inline void
+void
 strip_new_line (gchar *str)
 {
   gint nl = strlen (str) - 1;
diff -ruN ../yad-0.17.1.1-a/src/yad.h src/yad.h
