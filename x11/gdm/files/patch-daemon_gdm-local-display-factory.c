--- daemon/gdm-local-display-factory.c.orig	2022-01-12 14:15:56 UTC
+++ daemon/gdm-local-display-factory.c
@@ -28,7 +28,9 @@
 #include <glib-object.h>
 #include <gio/gio.h>
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #include "gdm-common.h"
 #include "gdm-manager.h"
@@ -61,8 +63,10 @@ struct _GdmLocalDisplayFactory
         /* FIXME: this needs to be per seat? */
         guint            num_failures;
 
+#ifdef WITH_SYSTEMD
         guint            seat_new_id;
         guint            seat_removed_id;
+#endif
         guint            seat_properties_changed_id;
 
         gboolean         seat0_graphics_check_timed_out;
@@ -94,9 +98,11 @@ static void     on_display_status_changed             
 
 static gboolean gdm_local_display_factory_sync_seats    (GdmLocalDisplayFactory *factory);
 static gpointer local_display_factory_object = NULL;
+#ifdef WITH_SYSTEMD
 static gboolean lookup_by_session_id (const char *id,
                                       GdmDisplay *display,
                                       gpointer    user_data);
+#endif
 
 G_DEFINE_TYPE (GdmLocalDisplayFactory, gdm_local_display_factory, GDM_TYPE_DISPLAY_FACTORY)
 
@@ -233,9 +239,9 @@ struct GdmDisplayServerConfiguration {
         const char *session_type;
 } display_server_configuration[] = {
 #ifdef ENABLE_WAYLAND_SUPPORT
-        { "wayland", GDM_KEY_WAYLAND_ENABLE, "/usr/bin/Xwayland", "wayland" },
+        { "wayland", GDM_KEY_WAYLAND_ENABLE, "/usr/local/bin/Xwayland", "wayland" },
 #endif
-        { "xorg", GDM_KEY_XORG_ENABLE, "/usr/bin/Xorg", "x11" },
+        { "xorg", GDM_KEY_XORG_ENABLE, X_SERVER, "x11" },
         { NULL, NULL, NULL },
 };
 
@@ -439,6 +445,7 @@ gdm_local_display_factory_create_transient_display (Gd
         return ret;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 finish_display_on_seat_if_waiting (GdmDisplayStore *display_store,
                                    GdmDisplay      *display,
@@ -493,6 +500,7 @@ on_session_registered_cb (GObject *gobject,
 
         finish_waiting_displays_on_seat (factory, "seat0");
 }
+#endif
 
 static void
 on_display_status_changed (GdmDisplay             *display,
@@ -540,7 +548,7 @@ on_display_status_changed (GdmDisplay             *dis
                  * if there isn't one.
                  */
                 if (is_local &&
-                    (g_strcmp0 (session_class, "greeter") != 0 || factory->active_vt == GDM_INITIAL_VT)) {
+                    (g_strcmp0 (session_class, "greeter") != 0)) {
                         /* reset num failures */
                         factory->num_failures = 0;
 
@@ -649,7 +657,9 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
         const char *legacy_session_types[] = { "x11", NULL };
         GdmDisplayStore *store;
         GdmDisplay      *display = NULL;
+#ifdef WITH_SYSTEMD
         g_autofree char *login_session_id = NULL;
+#endif
         gboolean wayland_enabled = FALSE, xorg_enabled = FALSE;
         g_autofree gchar *preferred_display_server = NULL;
         gboolean falling_back = FALSE;
@@ -679,7 +689,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
                 seat_supports_graphics = TRUE;
         }
 
-        if (g_strcmp0 (seat_id, "seat0") == 0) {
+        if (g_strcmp0 (seat_id, SEAT_ID) == 0) {
                 is_seat0 = TRUE;
 
                 falling_back = factory->num_failures > 0;
@@ -767,6 +777,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
                 return;
         }
 
+#ifdef WITH_SYSTEMD
         /* If we already have a login window, switch to it */
         if (gdm_get_login_window_session_id (seat_id, &login_session_id)) {
                 GdmDisplay *display;
@@ -784,6 +795,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
                         return;
                 }
         }
+#endif
 
         g_debug ("GdmLocalDisplayFactory: Adding display on seat %s", seat_id);
 
@@ -827,6 +839,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
         return;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 delete_display (GdmLocalDisplayFactory *factory,
                 const char             *seat_id) {
@@ -838,6 +851,7 @@ delete_display (GdmLocalDisplayFactory *factory,
         store = gdm_display_factory_get_display_store (GDM_DISPLAY_FACTORY (factory));
         gdm_display_store_foreach_remove (store, lookup_by_seat_id, (gpointer) seat_id);
 }
+#endif
 
 static gboolean
 gdm_local_display_factory_sync_seats (GdmLocalDisplayFactory *factory)
@@ -849,6 +863,8 @@ gdm_local_display_factory_sync_seats (GdmLocalDisplayF
         const char *seat;
 
         g_debug ("GdmLocalDisplayFactory: enumerating seats from logind");
+
+#ifdef WITH_SYSTEMD
         result = g_dbus_connection_call_sync (factory->connection,
                                               "org.freedesktop.login1",
                                               "/org/freedesktop/login1",
@@ -859,6 +875,18 @@ gdm_local_display_factory_sync_seats (GdmLocalDisplayF
                                               G_DBUS_CALL_FLAGS_NONE,
                                               -1,
                                               NULL, &error);
+#elif defined(WITH_CONSOLE_KIT)
+        result = g_dbus_connection_call_sync (factory->connection,
+                                              CK_NAME,
+                                              CK_MANAGER_PATH,
+                                              CK_MANAGER_INTERFACE,
+                                              "ListSeats",
+                                              NULL,
+                                              G_VARIANT_TYPE ("(a(so))"),
+                                              G_DBUS_CALL_FLAGS_NONE,
+                                              -1,
+                                              NULL, &error);
+#endif
 
         if (!result) {
                 g_warning ("GdmLocalDisplayFactory: Failed to issue method call: %s", error->message);
@@ -878,6 +906,7 @@ gdm_local_display_factory_sync_seats (GdmLocalDisplayF
         return TRUE;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 on_seat_new (GDBusConnection *connection,
              const gchar     *sender_name,
@@ -989,6 +1018,7 @@ lookup_by_tty (const char *id,
 
         return g_strcmp0 (tty_to_check, tty_to_find) == 0;
 }
+#endif
 
 #if defined(ENABLE_USER_DISPLAY_SERVER)
 static void
@@ -1166,6 +1196,7 @@ on_vt_changed (GIOChannel    *source,
 }
 #endif
 
+#ifdef WITH_SYSTEMD
 static void
 gdm_local_display_factory_start_monitor (GdmLocalDisplayFactory *factory)
 {
@@ -1215,10 +1246,12 @@ gdm_local_display_factory_start_monitor (GdmLocalDispl
         }
 #endif
 }
+#endif
 
 static void
 gdm_local_display_factory_stop_monitor (GdmLocalDisplayFactory *factory)
 {
+#ifdef WITH_SYSTEMD
         if (factory->seat_new_id) {
                 g_dbus_connection_signal_unsubscribe (factory->connection,
                                                       factory->seat_new_id);
@@ -1244,6 +1277,7 @@ gdm_local_display_factory_stop_monitor (GdmLocalDispla
                 factory->wait_to_finish_timeout_id = 0;
         }
 #endif
+#endif
 }
 
 static void
@@ -1298,7 +1332,9 @@ gdm_local_display_factory_start (GdmDisplayFactory *ba
                                  factory,
                                  0);
 
+#ifdef WITH_SYSTEMD
         gdm_local_display_factory_start_monitor (factory);
+#endif
         return gdm_local_display_factory_sync_seats (factory);
 }
 
