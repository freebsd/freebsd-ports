--- src/dialogs/power/dbus.vala.orig	2023-01-29 15:27:27 UTC
+++ src/dialogs/power/dbus.vala
@@ -25,7 +25,7 @@ namespace Budgie {
 	}
 
 	/* logind */
-	[DBus (name="org.freedesktop.login1.Manager")]
+	[DBus (name="org.freedesktop.ConsoleKit.Manager")]
 	public interface LogindRemote : Object {
 		public abstract string can_hibernate() throws DBusError, IOError;
 
