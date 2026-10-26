--- src/wm/wm.vala.orig	2022-08-30 16:36:31 UTC
+++ src/wm/wm.vala
@@ -26,8 +26,8 @@ namespace Budgie {
 	public const string PANEL_DBUS_NAME = "org.budgie_desktop.Panel";
 	public const string PANEL_DBUS_OBJECT_PATH = "/org/budgie_desktop/Panel";
 
-	public const string LOGIND_DBUS_NAME = "org.freedesktop.login1";
-	public const string LOGIND_DBUS_OBJECT_PATH = "/org/freedesktop/login1";
+	public const string LOGIND_DBUS_NAME = "org.freedesktop.ConsoleKit";
+	public const string LOGIND_DBUS_OBJECT_PATH = "/org/freedesktop/ConsoleKit/Manager";
 
 	/** Menu management */
 	public const string MENU_DBUS_NAME = "org.budgie_desktop.MenuManager";
@@ -168,7 +168,8 @@ namespace Budgie {
 		}
 
 		bool have_logind() {
-			return FileUtils.test("/run/systemd/seats", FileTest.EXISTS);
+			// Awful hack, but it is the only way
+			return FileUtils.test("/var/run/consolekit.pid", FileTest.EXISTS);
 		}
 
 		/* Hold onto our Raven proxy ref */
@@ -229,7 +230,7 @@ namespace Budgie {
 					logind_proxy.PrepareForSleep.connect(prepare_for_sleep);
 				}
 			} catch (Error e) {
-				warning("Failed to get LoginD proxy: %s", e.message);
+				warning("Failed to get ConsoleKit proxy: %s", e.message);
 			}
 		}
 
