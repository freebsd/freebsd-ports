--- lib/Items/PlankDockItem.vala.orig	2015-10-07 12:34:54 UTC
+++ lib/Items/PlankDockItem.vala
@@ -74,11 +74,11 @@ namespace Plank.Items
 		{
 			var items = new Gee.ArrayList<Gtk.MenuItem> ();
 			
-			var item = create_menu_item (_("Get _Help Online..."), "help");
+			var item = create_menu_item (_("Get _Help Online..."), "help-browser");
 			item.activate.connect (() => Application.get_default ().activate_action ("help", null));
 			items.add (item);
 			
-			item = create_menu_item (_("_Translate This Application..."), "locale");
+			item = create_menu_item (_("_Translate This Application..."), "preferences-desktop-locale");
 			item.activate.connect (() => Application.get_default ().activate_action ("translate", null));
 			items.add (item);
 			
