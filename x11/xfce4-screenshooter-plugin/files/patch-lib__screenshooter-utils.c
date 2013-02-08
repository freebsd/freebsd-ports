--- ./lib/screenshooter-utils.c.orig	2010-05-21 08:11:35.000000000 +0000
+++ ./lib/screenshooter-utils.c	2013-01-19 21:15:00.000000000 +0000
@@ -345,10 +345,17 @@
 void screenshooter_open_help (void)
 {
   GError *error_help = NULL;
+  gboolean result;
 
   /* Launch the help page and show an error dialog if there was an error. */
-  if (!g_spawn_command_line_async ("xfhelp4 xfce4-screenshooter.html",
-                                   &error_help))
+#if LIBXFCE4UTIL_CHECK_VERSION (4, 10, 0)
+  result = g_spawn_command_line_async("exo-open --launch TerminalEmulator man xfce4-screenshooter",
+                                      &error_help);
+#else
+  result = g_spawn_command_line_async ("xfhelp4 xfce4-screenshooter.html",
+                                       &error_help);
+#endif
+  if (G_UNLIKELY (result == FALSE))
     {
       screenshooter_error ("%s", error_help->message);
       g_error_free (error_help);
