--- libxklavier/xklavier.c.orig	Tue Nov  2 16:58:48 2004
+++ libxklavier/xklavier.c	Tue Nov 23 19:56:29 2004
@@ -536,7 +536,7 @@
                             int level, const char format[], va_list args )
 {
   time_t now = time( NULL );
-  fprintf( stdout, "[%08ld,%03d,%s:%s/] \t", now, level, file, function );
+  fprintf( stdout, "[%08ld,%03d,%s:%s/] \t", (long) now, level, file, function );
   vfprintf( stdout, format, args );
 }
 
@@ -700,9 +700,10 @@
 {
   if ( xklVTable == NULL )
   {
+    char *p;
     XklDebug( 0, "ERROR: XKL VTable is NOT initialized.\n" );
     /* force the crash! */
-    char *p = NULL; *p = '\0';
+    p = NULL; *p = '\0';
   }
 }
 
