
$FreeBSD$

--- panel/foobar-widget.c	2002/07/14 10:25:26	1.1
+++ panel/foobar-widget.c	2002/07/14 10:25:41
@@ -1068,7 +1068,7 @@
 				   FALSE, "apps");
 	foo->settings =
 		append_folder_menu(menu_bar, _("Settings"),  NULL, TRUE,
-			           "gnome/apps/Settings");
+			           "apps/Settings");
 	append_desktop_menu (menu_bar);
 
 	gtk_box_pack_start (GTK_BOX (foo->hbox), menu_bar, FALSE, FALSE, 0);
