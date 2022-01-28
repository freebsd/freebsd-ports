--- common/gdm-common.c.orig	2022-01-12 14:15:56 UTC
+++ common/gdm-common.c
@@ -36,7 +36,9 @@
 
 #include "gdm-common.h"
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #define GDM_DBUS_NAME                            "org.gnome.DisplayManager"
 #define GDM_DBUS_LOCAL_DISPLAY_FACTORY_PATH      "/org/gnome/DisplayManager/LocalDisplayFactory"
@@ -352,6 +354,412 @@ create_transient_display (GDBusConnection *connection,
         return TRUE;
 }
 
+#ifdef WITH_CONSOLE_KIT
+int
+sd_seat_can_graphical(const char *seat)
+{
+        // XXX
+        return 1;
+}
+
+int
+sd_session_get_service(const char *session,
+                       char **service)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        const char *value;
+        g_autoptr(GDBusConnection) connection = NULL;
+
+        if (session == NULL || !g_variant_is_object_path (session))
+                return -ENXIO;
+
+        connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &local_error);
+        if (connection == NULL) {
+                g_warning ("Failed to connect to the D-Bus daemon: %s", local_error->message);
+                return -ENXIO;
+        }
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             session,
+                                             CK_SESSION_INTERFACE,
+                                             "GetSessionService",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(s)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to determine session service: %s", local_error ? local_error->message : "");
+                g_error_free (local_error);
+                return -ENXIO;
+        }
+
+        g_variant_get (reply, "(s)", &value);
+        g_variant_unref (reply);
+
+        *service = g_strdup (value);
+
+        return 0;
+}
+
+int
+sd_session_get_uid(const char *session,
+                   uid_t *uid)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        g_autoptr(GDBusConnection) connection = NULL;
+        uid_t local_uid;
+
+        if (session == NULL || !g_variant_is_object_path (session))
+                return -ENXIO;
+
+        connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &local_error);
+        if (connection == NULL) {
+                g_warning ("Failed to connect to the D-Bus daemon: %s", local_error->message);
+                return -ENXIO;
+        }
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             session,
+                                             CK_SESSION_INTERFACE,
+                                             "GetUnixUser",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(u)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to get session for unix service: %s", local_error ? local_error->message : "");
+                g_error_free (local_error);
+                return -ENXIO;
+        }
+
+        g_variant_get (reply, "(u)", &local_uid);
+        g_variant_unref (reply);
+
+        *uid = local_uid;
+
+        return 0;
+}
+
+int
+sd_seat_get_sessions(const char   *seat,
+                     char       ***sessions,
+                     uid_t       **uid,
+                     unsigned int *n_uids)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        GVariantIter *iter;
+        gchar *value = NULL;
+        glong nchild;
+        g_autoptr(GDBusConnection) connection = NULL;
+
+        if (seat == NULL || !g_variant_is_object_path (seat))
+                return -ENXIO;
+
+        connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &local_error);
+        if (connection == NULL) {
+                g_warning ("Failed to connect to the D-Bus daemon: %s", local_error->message);
+                return -ENXIO;
+        }
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             seat,
+                                             CK_SEAT_INTERFACE,
+                                             "GetSessions",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(ao)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to list sessions: %s", local_error->message);
+                g_error_free (local_error);
+                return -ENXIO;
+        }
+
+        g_variant_get (reply, "(ao)", &iter);
+        g_variant_unref (reply);
+
+        nchild = g_variant_iter_n_children(iter);
+        *sessions = calloc(nchild, sizeof(gchar *));
+        if (*sessions == NULL) {
+                g_warning ("Unable to allocate memory for sessions array: %s", g_strerror(errno));
+                return -ENOMEM;
+        }
+
+        while (g_variant_iter_next (iter, "o", &value)) {
+                (*sessions)[nchild - 1] = g_strdup(value);
+        }
+        (*sessions)[nchild] = NULL;
+
+        g_variant_iter_free (iter);
+
+        return 0;
+}
+
+int
+sd_session_get_seat(const char *session,
+                    char      **seat)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        const char *value;
+        g_autoptr(GDBusConnection) connection = NULL;
+
+        if (session == NULL || !g_variant_is_object_path (session))
+                return -ENXIO;
+
+        connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &local_error);
+        if (connection == NULL) {
+                g_warning ("Failed to connect to the D-Bus daemon: %s", local_error->message);
+                return -ENXIO;
+        }
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             session,
+                                             CK_SESSION_INTERFACE,
+                                             "GetSeatId",
+                                             NULL, /* parameters */
+                                             G_VARIANT_TYPE ("(o)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to determine seat: %s", local_error ? local_error->message : "");
+                g_error_free (local_error);
+                return -ENXIO;
+        }
+
+        g_variant_get (reply, "(o)", &value);
+        g_variant_unref (reply);
+
+        *seat = g_strdup(value);
+
+        return 0;
+}
+
+int
+sd_pid_get_session(pid_t pid, char **session)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        const char *value;
+        g_autoptr(GDBusConnection) connection = NULL;
+
+        connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &local_error);
+        if (connection == NULL) {
+                g_warning ("Failed to connect to the D-Bus daemon: %s", local_error->message);
+                return -ENXIO;
+        }
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             CK_MANAGER_PATH,
+                                             CK_MANAGER_INTERFACE,
+                                             "GetSessionForUnixProcess",
+                                             g_variant_new ("(u)", pid),
+                                             G_VARIANT_TYPE ("(o)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to list sessions: %s", local_error ? local_error->message : "");
+                g_error_free (local_error);
+                return -ENXIO;
+        }
+
+        g_variant_get (reply, "(o)", &value);
+        g_variant_unref (reply);
+
+        *session = g_strdup (value);
+
+        return 0;
+}
+
+int
+sd_session_get_type(const char *session, char **type)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        const char *value;
+        g_autoptr(GDBusConnection) connection = NULL;
+
+        if (session == NULL || !g_variant_is_object_path (session))
+                return -ENXIO;
+
+        connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &local_error);
+        if (connection == NULL) {
+                g_warning ("Failed to connect to the D-Bus daemon: %s", local_error->message);
+                return -ENXIO;
+        }
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             session,
+                                             CK_SESSION_INTERFACE,
+                                             "GetSessionType",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(s)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to determine session type: %s", local_error ? local_error->message : "");
+                g_error_free (local_error);
+                return -ENXIO;
+        }
+
+        g_variant_get (reply, "(s)", &value);
+        g_variant_unref (reply);
+
+        *type = g_strdup (value);
+
+        return 0;
+}
+
+int
+sd_session_get_class(const char *session, char **class)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        const gchar *value;
+        g_autoptr(GDBusConnection) connection = NULL;
+
+        if (session == NULL || !g_variant_is_object_path (session))
+                return -ENXIO;
+
+        connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &local_error);
+        if (connection == NULL) {
+                g_warning ("Failed to connect to the D-Bus daemon: %s", local_error->message);
+                return -ENXIO;
+        }
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             session,
+                                             CK_SESSION_INTERFACE,
+                                             "GetSessionClass",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(s)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to determine session class: %s", local_error ? local_error->message : "");
+                g_error_free (local_error);
+                return -ENXIO;
+        }
+
+        g_variant_get (reply, "(s)", &value);
+        g_variant_unref (reply);
+
+        *class = g_strdup(value);
+
+        return 0;
+}
+
+int
+sd_session_get_state(const char *session, char **state)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        const char *value;
+        g_autoptr(GDBusConnection) connection = NULL;
+
+        if (session == NULL || !g_variant_is_object_path (session))
+                return -ENXIO;
+
+        connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &local_error);
+        if (connection == NULL) {
+                g_warning ("Failed to connect to the D-Bus daemon: %s", local_error->message);
+                return -ENXIO;
+        }
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             session,
+                                             CK_SESSION_INTERFACE,
+                                             "GetSessionState",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(s)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to determine session state: %s", local_error ? local_error->message : "");
+                g_error_free (local_error);
+                return -ENXIO;
+        }
+
+        g_variant_get (reply, "(s)", &value);
+        g_variant_unref (reply);
+
+        *state = g_strdup (value);
+
+        return 0;
+}
+
+int
+sd_uid_get_sessions(uid_t uid, int require_active, char ***sessions)
+{
+        GError *local_error = NULL;
+        GVariant *reply;
+        GVariantIter *iter;
+        gchar *value = NULL;
+        glong nchild;
+        g_autoptr(GDBusConnection) connection = NULL;
+
+        connection = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &local_error);
+        if (connection == NULL) {
+                g_warning ("Failed to connect to the D-Bus daemon: %s", local_error->message);
+                return -ENXIO;
+        }
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             CK_MANAGER_PATH,
+                                             CK_MANAGER_INTERFACE,
+                                             "GetSessionsForUnixUser",
+                                             g_variant_new ("(u)", uid),
+                                             G_VARIANT_TYPE ("(ao)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+        if (reply == NULL) {
+                g_warning ("Unable to list sessions: %s", local_error ? local_error->message : "");
+                g_error_free (local_error);
+                return -ENXIO;
+        }
+
+        g_variant_get (reply, "(ao)", &iter);
+        g_variant_unref (reply);
+
+        nchild = g_variant_iter_n_children(iter);
+        *sessions = calloc(nchild, sizeof(gchar *));
+        if (*sessions == NULL) {
+                g_warning ("Unable to allocate memory for sessions array: %s", g_strerror(errno));
+                return -ENOMEM;
+        }
+
+        while (g_variant_iter_next (iter, "o", &value)) {
+                (*sessions)[nchild - 1] = g_strdup(value);
+        }
+        (*sessions)[nchild] = NULL;
+
+        g_variant_iter_free (iter);
+
+        return 0;
+}
+#endif
+
 gboolean
 gdm_activate_session_by_id (GDBusConnection *connection,
                             const char      *seat_id,
@@ -360,6 +768,7 @@ gdm_activate_session_by_id (GDBusConnection *connectio
         GError *local_error = NULL;
         GVariant *reply;
 
+#if defined(WITH_SYSTEMD)
         reply = g_dbus_connection_call_sync (connection,
                                              "org.freedesktop.login1",
                                              "/org/freedesktop/login1",
@@ -370,7 +779,41 @@ gdm_activate_session_by_id (GDBusConnection *connectio
                                              G_DBUS_CALL_FLAGS_NONE,
                                              -1,
                                              NULL, &local_error);
+#elif defined(WITH_CONSOLE_KIT)
+        gboolean ret;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             seat_id,
+                                             CK_SEAT_INTERFACE,
+                                             "CanActivateSessions",
+                                             NULL,
+                                             G_VARIANT_TYPE ("(b)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
         if (reply == NULL) {
+                g_warning ("Unable to determine if can activate sessions: %s", local_error ? local_error->message : "");
+                g_error_free (local_error);
+                return FALSE;
+        }
+
+        g_variant_get (reply, "(b)", &ret);
+        if (ret != TRUE)
+                return ret;
+
+        reply = g_dbus_connection_call_sync (connection,
+                                             CK_NAME,
+                                             seat_id,
+                                             CK_SEAT_INTERFACE,
+                                             "ActivateSession",
+                                             g_variant_new ("(o)", session_id),
+                                             NULL,
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL, &local_error);
+#endif
+        if (reply == NULL) {
                 g_warning ("Unable to activate session: %s", local_error->message);
                 g_error_free (local_error);
                 return FALSE;
@@ -521,7 +964,7 @@ goto_login_session (GDBusConnection  *connection,
                 }
         }
 
-        if (! ret && g_strcmp0 (seat_id, "seat0") == 0) {
+        if (! ret && g_strcmp0 (seat_id, SEAT_ID) == 0) {
                 res = create_transient_display (connection, error);
                 if (res) {
                         ret = TRUE;
@@ -907,7 +1350,9 @@ gdm_find_display_session (GPid        pid,
 
                 return TRUE;
         } else {
+#ifdef ENODATA
                 if (res != -ENODATA)
+#endif
                         g_warning ("GdmCommon: Failed to retrieve session information for pid %d: %s",
                                    pid, strerror (-res));
         }
