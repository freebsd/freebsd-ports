--- backend/src/unix/MutterInputMonitor.cc.orig	2022-04-01 16:28:54 UTC
+++ backend/src/unix/MutterInputMonitor.cc
@@ -245,7 +245,7 @@ MutterInputMonitor::unregister_active_watch()
   if (watch_active != 0u)
     {
       GVariant *result = g_dbus_proxy_call_sync(
-        idle_proxy, "RemoveWatch", g_variant_new("(u)", watch_active), G_DBUS_CALL_FLAGS_NONE, 10000, NULL, &error);
+        idle_proxy, "RemoveWatch", g_variant_new("(u)", watch_active.get()), G_DBUS_CALL_FLAGS_NONE, 10000, NULL, &error);
       if (error == NULL)
         {
           g_variant_unref(result);
@@ -269,7 +269,7 @@ MutterInputMonitor::unregister_active_watch_async()
     {
       g_dbus_proxy_call(idle_proxy,
                         "RemoveWatch",
-                        g_variant_new("(u)", watch_active),
+                        g_variant_new("(u)", watch_active.get()),
                         G_DBUS_CALL_FLAGS_NONE,
                         10000,
                         NULL,
@@ -331,7 +331,7 @@ MutterInputMonitor::unregister_idle_watch()
   if (watch_idle != 0u)
     {
       GVariant *result = g_dbus_proxy_call_sync(
-        idle_proxy, "RemoveWatch", g_variant_new("(u)", watch_idle), G_DBUS_CALL_FLAGS_NONE, 10000, NULL, &error);
+        idle_proxy, "RemoveWatch", g_variant_new("(u)", watch_idle.get()), G_DBUS_CALL_FLAGS_NONE, 10000, NULL, &error);
       if (error == NULL)
         {
           g_variant_unref(result);
