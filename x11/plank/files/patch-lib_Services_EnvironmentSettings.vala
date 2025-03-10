--- lib/Services/EnvironmentSettings.vala.orig	2025-01-08 03:02:39 UTC
+++ lib/Services/EnvironmentSettings.vala
@@ -93,7 +93,7 @@ namespace Plank
 		public static unowned PantheonDesktopNotifications? try_get_instance ()
 		{
 			if (instance == null) {
-				var settings = try_create_settings ("org.pantheon.desktop.gala.notifications");
+				var settings = try_create_settings ("io.elementary.notifications");
 				if (settings != null && ("do-not-disturb" in settings.list_keys ()))
 					instance = (PantheonDesktopNotifications) Object.new (typeof (PantheonDesktopNotifications),
 						"settings", settings, "bind-flags", SettingsBindFlags.GET | SettingsBindFlags.INVERT_BOOLEAN, null);
