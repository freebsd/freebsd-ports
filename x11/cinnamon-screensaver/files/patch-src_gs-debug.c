--- src/gs-debug.c.orig	2013-11-25 08:35:36.406973707 +0000
+++ src/gs-debug.c	2013-11-25 08:37:07.941451522 +0000
@@ -57,8 +57,17 @@
 
         va_start (args, format);
 
+#ifdef __clang__
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
+#endif
+
         g_vsnprintf (buffer, 1024, format, args);
 
+#ifdef __clang__
+#pragma clang diagnostic pop
+#endif
+
         va_end (args);
 
         time (&the_time);
