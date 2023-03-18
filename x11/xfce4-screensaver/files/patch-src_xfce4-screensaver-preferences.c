--- src/xfce4-screensaver-preferences.c.orig	2023-03-17 17:09:57 UTC
+++ src/xfce4-screensaver-preferences.c
@@ -1700,6 +1700,10 @@ setup_for_lid_switch (void) {
     }
 }
 
+#ifdef __FreeBSD__
+extern char **environ;
+#endif
+
 static gchar **
 spawn_make_environment_for_display (GdkDisplay  *display,
                                     gchar      **envp) {
