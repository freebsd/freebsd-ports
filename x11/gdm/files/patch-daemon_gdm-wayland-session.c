--- daemon/gdm-wayland-session.c.orig	2023-09-14 15:27:04 UTC
+++ daemon/gdm-wayland-session.c
@@ -212,32 +212,7 @@ import_environment (State        *state,
 import_environment (State        *state,
                     GCancellable *cancellable)
 {
-        g_autoptr(GVariant) reply = NULL;
-        g_autoptr(GVariant) environment_variant = NULL;
-        g_autoptr(GError)   error = NULL;
-
-        reply = g_dbus_connection_call_sync (state->bus_connection,
-                                             "org.freedesktop.systemd1",
-                                             "/org/freedesktop/systemd1",
-                                             "org.freedesktop.DBus.Properties",
-                                             "Get",
-                                             g_variant_new ("(ss)",
-                                                            "org.freedesktop.systemd1.Manager",
-                                                            "Environment"),
-                                             NULL,
-                                             G_DBUS_CALL_FLAGS_NONE,
-                                             -1, cancellable, &error);
-
-        if (reply == NULL) {
-                g_debug ("could not fetch environment: %s", error->message);
-                return FALSE;
-        }
-
-        g_variant_get (reply, "(v)", &environment_variant);
-
-        state->environment = g_variant_dup_strv (environment_variant, NULL);
-
-        return TRUE;
+        return FALSE;
 }
 
 static void
