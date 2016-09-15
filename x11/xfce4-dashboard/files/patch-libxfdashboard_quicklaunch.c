--- libxfdashboard/quicklaunch.c.orig	2016-03-29 05:48:01 UTC
+++ libxfdashboard/quicklaunch.c
@@ -1295,7 +1295,7 @@ static void _xfdashboard_quicklaunch_set
 	XfdashboardQuicklaunchPrivate	*priv;
 	guint							i;
 	const gchar						*defaultApplications[]=	{
-																"exo-web-browser.desktop"
+																"exo-web-browser.desktop",
 																"exo-mail-reader.desktop",
 																"exo-file-manager.desktop",
 																"exo-terminal-emulator.desktop",
