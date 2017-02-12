--- src/process-window.c.orig	2017-02-08 22:08:25 UTC
+++ src/process-window.c
@@ -247,7 +247,7 @@ xtm_process_window_init (XtmProcessWindo
 	window->settings_button = xtm_settings_tool_button_new ();
 	gtk_toolbar_insert (GTK_TOOLBAR (window->toolbar), GTK_TOOL_ITEM (window->settings_button), 1);
 
-	icon = gtk_image_new_from_icon_name ("xc_crosshair", GTK_ICON_SIZE_LARGE_TOOLBAR);
+	icon = gtk_image_new_from_icon_name ("dialog-information", GTK_ICON_SIZE_LARGE_TOOLBAR);
 	xwininfo = gtk_tool_button_new (icon, _("Identify Window"));
 	gtk_widget_set_tooltip_text (GTK_WIDGET (xwininfo), _("Identify an open window by clicking on it."));
 	gtk_toolbar_insert (GTK_TOOLBAR (window->toolbar), GTK_TOOL_ITEM (xwininfo), 2);
