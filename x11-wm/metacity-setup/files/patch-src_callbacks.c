--- src/callbacks.c.orig	Tue May 28 11:52:13 2002
+++ src/callbacks.c	Tue May 28 11:53:24 2002
@@ -30,9 +30,7 @@
 	gchar *possibleThemeDirs[4] =
 		{ g_build_filename (g_get_home_dir (), ".metacity", "themes",
 				    NULL),
-		"/gnome/head/INSTALL/share/metacity/themes",
-		"/usr/share/metacity/themes",
-		"/usr/local/share/metacity/themes"
+		"%%X11BASE%%/share/gnome/metacity/themes"
 	};
 	for (i = 0; i < 4; i++)
 	{
