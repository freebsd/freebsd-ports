--- src/info2html/main.c.orig	Fri Oct 10 02:53:54 2003
+++ src/info2html/main.c	Fri Oct 10 02:54:23 2003
@@ -125,11 +125,11 @@
 
                 for(i = 0; i < ndirs; i++) {
                         ext = "";
-                        buf = g_strdup_printf (buf, "%s/%s.info", dirs[i], args[0]);
+                        buf = g_strdup_printf ("%s/%s.info", dirs[i], args[0]);
                         if(file_exists(buf))
                                 break;
 			g_free (buf);
-                        buf = g_strdup_printf (buf, "%s/%s", dirs[i], args[0]);
+                        buf = g_strdup_printf ("%s/%s", dirs[i], args[0]);
                         if(file_exists(buf)) {
                                 no_info = TRUE;
                                 break;
@@ -141,7 +141,7 @@
                         if(file_exists(buf))
                                 break;
 			g_free (buf);
-			buf = g_strdup_printf (buf, "%s/%s.gz", dirs[i], args[0]);
+			buf = g_strdup_printf ("%s/%s.gz", dirs[i], args[0]);
                         if(file_exists(buf)) {
                                 no_info = TRUE;
                                 break;
