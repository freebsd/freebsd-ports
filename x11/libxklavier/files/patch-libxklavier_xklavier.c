--- libxklavier/xklavier.c.orig	Sat Apr 15 21:14:40 2006
+++ libxklavier/xklavier.c	Tue Jun 13 00:07:32 2006
@@ -394,7 +394,7 @@ xkl_default_log_appender(const gchar fil
 			 gint level, const gchar format[], va_list args)
 {
 	time_t now = time(NULL);
-	fprintf(stdout, "[%08ld,%03d,%s:%s/] \t", now, level, file,
+	fprintf(stdout, "[%08ld,%03d,%s:%s/] \t", (long)now, level, file,
 		function);
 	vfprintf(stdout, format, args);
 }
