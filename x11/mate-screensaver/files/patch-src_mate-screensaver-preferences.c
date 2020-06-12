--- src/mate-screensaver-preferences.c.orig	2020-02-10 12:35:28 UTC
+++ src/mate-screensaver-preferences.c
@@ -1337,9 +1337,7 @@ setup_for_root_user (void)
 }
 
 /* copied from gs-window-x11.c */
-#ifndef _GNU_SOURCE
 extern char **environ;
-#endif
 
 static gchar **
 spawn_make_environment_for_display (GdkDisplay *display,
