--- panel/menu.c.orig	Sat Jul 13 23:17:04 2002
+++ panel/menu.c	Sat Jul 13 23:17:33 2002
@@ -158,7 +158,7 @@
 	/*just load the menus from disk, don't make the widgets
 	  this just reads the .desktops of the top most directory
 	  and a level down*/
-	menu = gnome_datadir_file ("gnome/apps");
+	menu = gnome_datadir_file ("apps");
 	if (menu != NULL)
 		fr_read_dir (NULL, menu, NULL, NULL, 2);
 	g_free (menu);
@@ -3680,7 +3680,7 @@
 		    gboolean launcher_add,
 		    gboolean favourites_add)
 {
-	char *menudir = gnome_datadir_file ("gnome/apps");
+	char *menudir = gnome_datadir_file ("apps");
 
 	if (menudir &&
 	    g_file_test (menudir, G_FILE_TEST_ISDIR)) {
@@ -4847,8 +4847,8 @@
 	gtk_menu_append (GTK_MENU (submenu), submenuitem);
 	gtk_signal_connect(GTK_OBJECT(submenuitem), "activate",
 			   GTK_SIGNAL_FUNC(add_menu_to_panel),
-			   "gnome/apps");
-	setup_internal_applet_drag(submenuitem, "MENU:gnome/apps");
+			   "apps");
+	setup_internal_applet_drag(submenuitem, "MENU:apps");
 
 	submenuitem = gtk_menu_item_new ();
 	gtk_widget_lock_accelerators (menuitem);
