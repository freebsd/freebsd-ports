--- src/exec-tool-button.c.orig	2014-12-23 21:35:43 UTC
+++ src/exec-tool-button.c
@@ -51,7 +51,7 @@ xtm_exec_tool_button_init (XtmExecToolButton *button)
 {
 	GtkWidget *menu;
 
-	gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON (button), "gtk-execute");
+	gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON (button), "system-run");
 	gtk_tool_button_set_use_underline (GTK_TOOL_BUTTON (button), TRUE);
 
 	menu = construct_menu ();
@@ -189,19 +189,19 @@ construct_menu (void)
 
 	/* Find a runner program */
 	if (program_exists ("xfrun4"))
-		menu_append_item (GTK_MENU (menu), _("Run Program..."), "xfrun4", "gtk-execute");
+		menu_append_item (GTK_MENU (menu), _("Run Program..."), "xfrun4", "system-run");
 	else if (program_exists ("gmrun"))
-		menu_append_item (GTK_MENU (menu), _("Run Program..."), "gmrun", "gtk-execute");
+		menu_append_item (GTK_MENU (menu), _("Run Program..."), "gmrun", "system-run");
 	else if (program_exists ("gexec"))
-		menu_append_item (GTK_MENU (menu), _("Run Program..."), "gexec", "gtk-execute");
+		menu_append_item (GTK_MENU (menu), _("Run Program..."), "gexec", "system-run");
 	/* Find an applications-listing program */
 	if (program_exists ("xfce4-appfinder"))
-		menu_append_item (GTK_MENU (menu), _("Application Finder"), "xfce4-appfinder", "xfce4-appfinder");
+		menu_append_item (GTK_MENU (menu), _("Application Finder"), "xfce4-appfinder", "utilities-system-monitor");
 	/* Find a terminal emulator */
 	if (program_exists ("exo-open"))
-		menu_append_item (GTK_MENU (menu), _("Terminal emulator"), "exo-open --launch TerminalEmulator", "terminal");
+		menu_append_item (GTK_MENU (menu), _("Terminal emulator"), "exo-open --launch TerminalEmulator", "utilities-terminal");
 	else if (program_exists ("xterm"))
-		menu_append_item (GTK_MENU (menu), _("XTerm"), "xterm -fg grey -bg black", "terminal");
+		menu_append_item (GTK_MENU (menu), _("XTerm"), "xterm -fg grey -bg black", "utilities-terminal");
 
 	gtk_widget_show_all (menu);
 
