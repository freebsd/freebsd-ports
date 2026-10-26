--- src/dialogs/power/window.vala.orig	2025-11-09 13:21:57 UTC
+++ src/dialogs/power/window.vala
@@ -13,7 +13,7 @@ namespace Budgie {
 using Gtk;
 
 namespace Budgie {
-	const string LOGIND_LOGIN = "org.freedesktop.login1";
+	const string LOGIND_LOGIN = "org.freedesktop.ConsoleKit";
 	const string G_SESSION = "org.gnome.SessionManager";
 
 	/**
@@ -176,9 +176,9 @@ namespace Budgie {
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
