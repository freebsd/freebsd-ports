--- preview_pane.c.orig	Wed Jun 23 11:35:18 2004
+++ preview_pane.c	Wed Jun 23 11:37:07 2004
@@ -24,16 +24,19 @@
 GtkWidget* create_preview_pane(void)
 {
 	GtkBox* box = GTK_BOX(unfocussable(gtk_vbox_new(FALSE, 5)));
+	GtkWidget* frame;
 
 	{
 		gint i;
+		GtkWidget *item;
+		GSList* group = NULL;
 
 		GtkWidget *menubar = unfocussable(gtk_menu_bar_new());
 
 		GtkWidget *menu = unfocussable(gtk_menu_new());
 		gtk_menu_shell_append(GTK_MENU_SHELL(menu), unfocussable(gtk_tearoff_menu_item_new()));
 
-		GtkWidget *item = unfocussable(gtk_menu_item_new_with_label("Menu"));
+		item = unfocussable(gtk_menu_item_new_with_label("Menu"));
 		gtk_menu_shell_append(GTK_MENU_SHELL(menubar), item);
 		gtk_menu_item_set_submenu(GTK_MENU_ITEM(item), menu);
 
@@ -51,7 +54,6 @@
 
 		gtk_menu_shell_append(GTK_MENU_SHELL(menu), unfocussable(gtk_separator_menu_item_new()));
 
-		GSList* group = NULL;
 		for (i = 0; i < MENU_PREVIEW_ITEMS; i++)
 		{
 			item = unfocussable(gtk_radio_menu_item_new_with_label(group, "Radio"));
@@ -77,6 +79,7 @@
 	{
 		GtkToolbar* toolbar = GTK_TOOLBAR(unfocussable(gtk_toolbar_new()));
 		GtkWidget* button;
+		GtkRadioButton* radio;
 
 		button = unfocussable(gtk_check_button_new_with_label("Check 1"));
 		gtk_toolbar_append_widget(toolbar, button, "Tooltip", "");
@@ -87,7 +90,6 @@
 
 		gtk_toolbar_append_space(toolbar);
 
-		GtkRadioButton* radio;
 		
 		radio = GTK_RADIO_BUTTON(unfocussable(gtk_radio_button_new_with_label(NULL, "Radio 1")));
 		gtk_toolbar_append_widget(toolbar, GTK_WIDGET(radio), "Tooltip", "");
@@ -143,7 +145,7 @@
 		gtk_box_pack_start(box, GTK_WIDGET(hbox), FALSE, FALSE, 0);
 	}
 
-	GtkWidget* frame = unfocussable(gtk_frame_new("Preview"));
+	frame = unfocussable(gtk_frame_new("Preview"));
 	gtk_container_add(GTK_CONTAINER(frame), GTK_WIDGET(box));
 
 	return frame;
