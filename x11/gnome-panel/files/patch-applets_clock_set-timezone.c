--- trunk/applets/clock/set-timezone.c	2008/02/28 20:48:16	10908
+++ applets/clock/set-timezone.c	2008/04/02 15:08:34	10972
@@ -139,6 +139,9 @@
         DBusError dbus_error;
 	gint res = 0;
 
+        pk_caller = NULL;
+        pk_action = NULL;
+
 	system_bus = dbus_g_connection_get_connection (get_system_bus ());
 	if (system_bus == NULL)
 		goto out;
@@ -147,9 +150,6 @@
 	if (pk_context == NULL)
 		goto out;
 	
-        pk_caller = NULL;
-        pk_action = NULL;
-
         pk_action = polkit_action_new ();
         polkit_action_set_action_id (pk_action, pk_action_id);
 
