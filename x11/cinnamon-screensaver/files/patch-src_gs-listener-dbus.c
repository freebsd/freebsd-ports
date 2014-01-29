--- src/gs-listener-dbus.c.orig	2013-11-25 08:35:49.853972866 +0000
+++ src/gs-listener-dbus.c	2013-11-25 08:38:02.592963642 +0000
@@ -359,7 +359,18 @@
 
         va_list args;
         va_start (args, format);
+
+#ifdef __clang__
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
+#endif
+
         vsnprintf (buf, sizeof (buf), format, args);
+
+#ifdef __clang__
+#pragma clang diagnostic pop
+#endif
+
         va_end (args);
 
         gs_debug (buf);
