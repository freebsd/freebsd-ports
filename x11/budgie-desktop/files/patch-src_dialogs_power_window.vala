--- src/dialogs/power/window.vala.orig	2023-01-29 15:27:27 UTC
+++ src/dialogs/power/window.vala
@@ -13,7 +13,7 @@ using Gdk;
 using Gtk;
 
 namespace Budgie {
-	const string LOGIND_LOGIN = "org.freedesktop.login1";
+	const string LOGIND_LOGIN = "org.freedesktop.ConsoleKit";
 	const string G_SESSION = "org.gnome.SessionManager";
 
 	/**
@@ -181,9 +181,9 @@ namespace Budgie {
 		 */
 		private async void setup_dbus() {
 			try {
-				logind = yield Bus.get_proxy(BusType.SYSTEM, LOGIND_LOGIN, "/org/freedesktop/login1");
+				logind = yield Bus.get_proxy(BusType.SYSTEM, LOGIND_LOGIN, "/org/freedesktop/ConsoleKit/Manager");
 			} catch (Error e) {
-				warning("Unable to connect to logind: %s", e.message);
+				warning("Unable to connect to ConsoleKit daemon: %s", e.message);
 			}
 
 			try {
