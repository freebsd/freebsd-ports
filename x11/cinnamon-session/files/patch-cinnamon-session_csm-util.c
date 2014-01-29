--- cinnamon-session/csm-util.c.orig	2013-11-24 01:21:47.608721927 +0000
+++ cinnamon-session/csm-util.c	2013-11-24 01:22:17.505990366 +0000
@@ -401,10 +401,17 @@
         char           *msg;
         va_list         args;
 
+#ifdef __clang__
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
+#endif
         va_start (args, format);
         msg = g_strdup_vprintf (format, args);
         va_end (args);
 
+#ifdef __clang__
+#pragma clang diagnostic pop
+#endif
         /* If option parsing failed, Gtk won't have been initialized... */
         if (!gdk_display_get_default ()) {
                 if (!gtk_init_check (NULL, NULL)) {
