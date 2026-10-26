--- src/wm/wm.vala.orig	2025-11-09 13:21:57 UTC
+++ src/wm/wm.vala
@@ -26,8 +26,8 @@ namespace Budgie {
 	public const string PANEL_DBUS_NAME = "org.budgie_desktop.Panel";
 	public const string PANEL_DBUS_OBJECT_PATH = "/org/budgie_desktop/Panel";
 
-	public const string LOGIND_DBUS_NAME = "org.freedesktop.login1";
-	public const string LOGIND_DBUS_OBJECT_PATH = "/org/freedesktop/login1";
+	public const string LOGIND_DBUS_NAME = "org.freedesktop.ConsoleKit";
+	public const string LOGIND_DBUS_OBJECT_PATH = "/org/freedesktop/ConsoleKit/Manager";
 
 	public const string POWER_DIALOG_DBUS_NAME = "org.buddiesofbudgie.PowerDialog";
 	public const string POWER_DIALOG_DBUS_OBJECT_PATH = "/org/buddiesofbudgie/PowerDialog";
@@ -196,7 +196,8 @@ namespace Budgie {
 		}
 
 		bool have_logind() {
-			return FileUtils.test("/run/systemd/seats", FileTest.EXISTS);
+			// Awful hack, but it is the only way
+			return FileUtils.test("/var/run/consolekit.pid", FileTest.EXISTS);
 		}
 
 		/* Hold onto our ScreenshotControl proxy ref */
@@ -263,7 +264,7 @@ namespace Budgie {
 					logind_proxy.PrepareForSleep.connect(prepare_for_sleep);
 				}
 			} catch (Error e) {
-				warning("Failed to get LoginD proxy: %s", e.message);
+				warning("Failed to get ConsoleKit proxy: %s", e.message);
 			}
 		}
 
