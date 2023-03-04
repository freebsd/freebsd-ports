--- src/panel/applets/user-indicator/UserIndicatorWindow.vala.orig	2023-01-29 15:27:27 UTC
+++ src/panel/applets/user-indicator/UserIndicatorWindow.vala
@@ -11,7 +11,7 @@
 
 public const string ACCOUNTSSERVICE_ACC = "org.freedesktop.Accounts";
 public const string ACCOUNTSSERVICE_USER = "org.freedesktop.Accounts.User";
-public const string LOGIND_LOGIN = "org.freedesktop.login1";
+public const string LOGIND_LOGIN = "org.freedesktop.ConsoleKit";
 public const string G_SESSION = "org.gnome.SessionManager";
 
 public const string UNABLE_CONTACT = "Unable to contact ";
@@ -61,9 +61,9 @@ public class UserIndicatorWindow : Budgie.Popover {
 		}
 
 		try {
-			logind_interface = yield Bus.get_proxy(BusType.SYSTEM, LOGIND_LOGIN, "/org/freedesktop/login1");
+			logind_interface = yield Bus.get_proxy(BusType.SYSTEM, LOGIND_LOGIN, "/org/freedesktop/ConsoleKit/Manager");
 		} catch (Error e) {
-			warning(UNABLE_CONTACT + "logind: %s", e.message);
+			warning(UNABLE_CONTACT + "ConsoleKit: %s", e.message);
 		}
 
 		try {
@@ -117,8 +117,8 @@ public class UserIndicatorWindow : Budgie.Popover {
 		items.add(user_section);
 		items.add(separator);
 		items.add(lock_menu);
-		items.add(suspend_menu);
-		items.add(hibernate_menu);
+		//items.add(suspend_menu);
+		//items.add(hibernate_menu);
 		items.add(reboot_menu);
 		items.add(shutdown_menu);
 
