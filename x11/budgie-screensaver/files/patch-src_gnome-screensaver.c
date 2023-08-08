--- src/gnome-screensaver.c.orig	2022-06-11 04:30:52 UTC
+++ src/gnome-screensaver.c
@@ -44,7 +44,7 @@ gboolean attempt_gjs_screensaver_kill (gpointer data) 
 	argv[0] =  "pkill";
 	argv[1] = "-9";
 	argv[2] = "-f";
-	argv[3] = "'/usr/bin/gjs /usr/share/gnome-shell/org.gnome.ScreenSaver'";
+	argv[3] = "'%%PREFIX%%/bin/gjs %%PREFIX%%/share/gnome-shell/org.gnome.ScreenSaver'";
 	argv[4] = NULL;
 
 	g_autoptr(GError) error = NULL;
