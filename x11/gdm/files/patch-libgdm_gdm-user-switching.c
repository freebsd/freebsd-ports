--- libgdm/gdm-user-switching.c.orig	2022-01-12 14:15:56 UTC
+++ libgdm/gdm-user-switching.c
@@ -31,7 +31,9 @@
 #include <glib-object.h>
 #include <gio/gio.h>
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #include "common/gdm-common.h"
 #include "gdm-user-switching.h"
@@ -76,6 +78,7 @@ activate_session_id (GDBusConnection  *connection,
 {
         GVariant *reply;
 
+#if defined(WITH_SYSTEMD)
         reply = g_dbus_connection_call_sync (connection,
                                              "org.freedesktop.login1",
                                              "/org/freedesktop/login1",
@@ -86,6 +89,18 @@ activate_session_id (GDBusConnection  *connection,
                                              G_DBUS_CALL_FLAGS_NONE,
                                              -1,
                                              cancellable, error);
+#elif defined(WITH_CONSOLE_KIT)
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             seat_id,
+                                             CK_SEAT_INTERFACE,
+                                             "ActivateSession",
+                                             g_variant_new ("(o)", session_id),
+                                             NULL,
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, error);
+#endif
         if (reply == NULL) {
                 g_prefix_error (error, _("Unable to activate session: "));
                 return FALSE;
@@ -227,7 +242,7 @@ goto_login_session (GDBusConnection  *connection,
                 }
         }
 
-        if (! ret && g_strcmp0 (seat_id, "seat0") == 0) {
+        if (! ret && g_strcmp0 (seat_id, SEAT_ID) == 0) {
                 res = create_transient_display (connection, cancellable, error);
                 if (res) {
                         ret = TRUE;
