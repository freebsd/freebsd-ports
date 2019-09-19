--- plugins/applicationsmenu/applicationsmenu.c.orig	2019-04-05 19:49:05 UTC
+++ plugins/applicationsmenu/applicationsmenu.c
@@ -72,6 +72,7 @@ struct _ApplicationsMenuPlugin
 
   gulong           style_set_id;
   gulong           screen_changed_id;
+  gulong           theme_changed_id;
 };
 
 enum
@@ -209,9 +210,13 @@ applications_menu_plugin_class_init (ApplicationsMenuP
 static void
 applications_menu_plugin_init (ApplicationsMenuPlugin *plugin)
 {
+  GtkIconTheme *icon_theme;
+
   /* init garcon environment */
   garcon_set_environment_xdg (GARCON_ENVIRONMENT_XFCE);
 
+  icon_theme = gtk_icon_theme_get_default ();
+
   plugin->button = xfce_panel_create_toggle_button ();
   xfce_panel_plugin_add_action_widget (XFCE_PANEL_PLUGIN (plugin), plugin->button);
   gtk_container_add (GTK_CONTAINER (plugin), plugin->button);
@@ -244,6 +249,10 @@ applications_menu_plugin_init (ApplicationsMenuPlugin 
                                                    G_CALLBACK (applications_menu_button_theme_changed), plugin);
   plugin->screen_changed_id = g_signal_connect_swapped (G_OBJECT (plugin->button), "screen-changed",
                                                         G_CALLBACK (applications_menu_button_theme_changed), plugin);
+  plugin->theme_changed_id = g_signal_connect_swapped (G_OBJECT (icon_theme),
+                                                       "changed",
+                                                       G_CALLBACK (applications_menu_plugin_set_garcon_menu),
+                                                       plugin);
 }
 
 
@@ -443,6 +452,7 @@ static void
 applications_menu_plugin_free_data (XfcePanelPlugin *panel_plugin)
 {
   ApplicationsMenuPlugin *plugin = XFCE_APPLICATIONS_MENU_PLUGIN (panel_plugin);
+  GtkIconTheme           *icon_theme;
 
   if (plugin->menu != NULL)
     gtk_widget_destroy (plugin->menu);
@@ -457,6 +467,14 @@ applications_menu_plugin_free_data (XfcePanelPlugin *p
     {
       g_signal_handler_disconnect (plugin->button, plugin->screen_changed_id);
       plugin->screen_changed_id = 0;
+    }
+
+  if (plugin->theme_changed_id != 0)
+    {
+      icon_theme = gtk_icon_theme_get_default ();
+      g_signal_handler_disconnect (G_OBJECT (icon_theme),
+                                   plugin->theme_changed_id);
+      plugin->theme_changed_id = 0;
     }
 
   g_free (plugin->button_title);
