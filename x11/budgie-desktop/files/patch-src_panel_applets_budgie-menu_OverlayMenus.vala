--- src/panel/applets/budgie-menu/OverlayMenus.vala.orig	2023-01-29 15:27:27 UTC
+++ src/panel/applets/budgie-menu/OverlayMenus.vala
@@ -17,7 +17,7 @@ using Gtk;
  * Class to contain our overlay menu items
  */
 public class OverlayMenus : Revealer {
-	const string LOGIND_LOGIN = "org.freedesktop.login1";
+	const string LOGIND_LOGIN = "org.freedesktop.ConsoleKit";
 	const string G_SESSION = "org.gnome.SessionManager";
 
 	private Stack? stack = null;
