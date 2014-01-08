Use generic icon to avoid menu item without icon (especially with GNOME icons
theme).

--- ./src/exec-tool-button.c.orig	2014-01-08 18:42:02.000000000 +0000
+++ ./src/exec-tool-button.c	2014-01-08 21:43:47.000000000 +0000
@@ -179,7 +179,7 @@
 		menu_append_item (GTK_MENU (menu), _("Run Program..."), "gexec", "gtk-execute");
 	/* Find an applications-listing program */
 	if (program_exists ("xfce4-appfinder"))
-		menu_append_item (GTK_MENU (menu), _("Application Finder"), "xfce4-appfinder", "xfce4-appfinder");
+		menu_append_item (GTK_MENU (menu), _("Application Finder"), "xfce4-appfinder", "utilities-system-monitor");
 	/* Find a terminal emulator */
 	if (program_exists ("exo-open"))
 		menu_append_item (GTK_MENU (menu), _("Terminal emulator"), "exo-open --launch TerminalEmulator", "terminal");
