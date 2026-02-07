--- lib/dbusmenu-importer/importer.c.orig	2021-01-01 20:18:10 UTC
+++ lib/dbusmenu-importer/importer.c
@@ -25,7 +25,7 @@ struct _DBusMenuImporter
 	GObject parent_instance;
 	char *bus_name;
 	char *object_path;
-	ulong name_id;
+	gulong name_id;
 	GCancellable *cancellable;
 	DBusMenuXml *proxy;
 	DBusMenuModel *top_model;
