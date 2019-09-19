--- libxfdashboard/application-database.c.orig	2018-04-25 20:40:40 UTC
+++ libxfdashboard/application-database.c
@@ -118,14 +118,11 @@ static void _xfdashboard_application_database_add_hash
 static void _xfdashboard_application_database_on_application_menu_reload_required(XfdashboardApplicationDatabase *self,
 																					gpointer inUserData)
 {
-	GarconMenu		*menu;
-	GError			*error;
+	GarconMenu		*menu=GARCON_MENU(inUserData);
+	GError			*error=NULL;
 
 	g_return_if_fail(XFDASHBOARD_IS_APPLICATION_DATABASE(self));
-	g_return_if_fail(GARCON_IS_MENU(inUserData));
-
-	menu=GARCON_MENU(inUserData);
-	error=NULL;
+	g_return_if_fail(GARCON_IS_MENU(menu));
 
 	/* Reload application menu. This also emits all necessary signals. */
 	XFDASHBOARD_DEBUG(self, APPLICATIONS,
