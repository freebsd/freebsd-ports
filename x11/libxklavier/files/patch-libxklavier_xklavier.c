--- libxklavier/xklavier.c.orig	Tue Dec 13 00:52:26 2005
+++ libxklavier/xklavier.c	Tue Dec 13 00:52:45 2005
@@ -606,7 +606,7 @@
                             int level, const char format[], va_list args )
 {
   time_t now = time( NULL );
-  fprintf( stdout, "[%08ld,%03d,%s:%s/] \t", now, level, file, function );
+  fprintf( stdout, "[%08ld,%03d,%s:%s/] \t", (long) now, level, file, function );
   vfprintf( stdout, format, args );
 }
 
