--- src/daemon/bsd/plugins/power/gsd-power-manager.c.orig	2025-09-07 12:35:19 UTC
+++ src/daemon/bsd/plugins/power/gsd-power-manager.c
@@ -75,9 +75,9 @@
 #define GSD_POWER_MANAGER_NOTIFY_TIMEOUT_SHORT          10 * 1000 /* ms */
 #define GSD_POWER_MANAGER_NOTIFY_TIMEOUT_LONG           30 * 1000 /* ms */
 
-#define SYSTEMD_DBUS_NAME                       "org.freedesktop.login1"
-#define SYSTEMD_DBUS_PATH                       "/org/freedesktop/login1"
-#define SYSTEMD_DBUS_INTERFACE                  "org.freedesktop.login1.Manager"
+#define CK_DBUS_NAME                       "org.freedesktop.ConsoleKit"
+#define CK_DBUS_PATH                       "/org/freedesktop/ConsoleKit/Manager"
+#define CK_DBUS_INTERFACE                  "org.freedesktop.ConsoleKit.Manager"
 
 /* Time between notifying the user about a critical action and the action itself in UPower. */
 #define GSD_ACTION_DELAY 20
@@ -1151,7 +1151,7 @@ action_poweroff (GsdPowerManager *manager)
 action_poweroff (GsdPowerManager *manager)
 {
         if (manager->logind_proxy == NULL) {
-                g_warning ("no systemd support");
+                g_warning ("no ConsoleKit support");
                 return;
         }
         g_dbus_proxy_call (manager->logind_proxy,
@@ -1168,7 +1168,7 @@ action_suspend (GsdPowerManager *manager)
 action_suspend (GsdPowerManager *manager)
 {
         if (manager->logind_proxy == NULL) {
-                g_warning ("no systemd support");
+                g_warning ("no ConsoleKit support");
                 return;
         }
         g_dbus_proxy_call (manager->logind_proxy,
@@ -1185,7 +1185,7 @@ action_hibernate (GsdPowerManager *manager)
 action_hibernate (GsdPowerManager *manager)
 {
         if (manager->logind_proxy == NULL) {
-                g_warning ("no systemd support");
+                g_warning ("no ConsoleKit support");
                 return;
         }
         g_dbus_proxy_call (manager->logind_proxy,
@@ -2951,13 +2951,13 @@ gsd_power_manager_initable_init (GInitable     *initab
                         g_dbus_proxy_new_for_bus_sync (G_BUS_TYPE_SYSTEM,
                                                        0,
                                                        NULL,
-                                                       SYSTEMD_DBUS_NAME,
-                                                       SYSTEMD_DBUS_PATH,
-                                                       SYSTEMD_DBUS_INTERFACE,
+                                                       CK_DBUS_NAME,
+                                                       CK_DBUS_PATH,
+                                                       CK_DBUS_INTERFACE,
                                                        NULL,
                                                        error);
                 if (manager->logind_proxy == NULL) {
-                        g_debug ("No systemd (logind) support, disabling plugin");
+                        g_debug ("No ConsoleKit support, disabling plugin");
                         return FALSE;
                 }
         }
