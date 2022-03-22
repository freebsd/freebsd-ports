--- daemon/gdm-local-display-factory.c.orig	2022-03-21 18:12:40 UTC
+++ daemon/gdm-local-display-factory.c
@@ -29,10 +29,12 @@
 #include <gio/gio.h>
 
 #ifdef HAVE_UDEV
-#include <gudev/gudev.h>
+#undef HAVE_UDEV
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #include "gdm-common.h"
 #include "gdm-manager.h"
@@ -68,8 +70,10 @@ struct _GdmLocalDisplayFactory
         /* FIXME: this needs to be per seat? */
         guint            num_failures;
 
+#ifdef WITH_SYSTEMD
         guint            seat_new_id;
         guint            seat_removed_id;
+#endif
         guint            seat_properties_changed_id;
 
         gboolean         seat0_has_platform_graphics;
@@ -106,9 +110,11 @@ static gpointer local_display_factory_object = NULL;
 
 static gboolean gdm_local_display_factory_sync_seats    (GdmLocalDisplayFactory *factory);
 static gpointer local_display_factory_object = NULL;
+#ifdef WITH_SYSTEMD
 static gboolean lookup_by_session_id (const char *id,
                                       GdmDisplay *display,
                                       gpointer    user_data);
+#endif
 
 G_DEFINE_TYPE (GdmLocalDisplayFactory, gdm_local_display_factory, GDM_TYPE_DISPLAY_FACTORY)
 
@@ -245,9 +251,9 @@ struct GdmDisplayServerConfiguration {
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
 
@@ -373,7 +379,6 @@ gdm_local_display_factory_create_transient_display (Gd
         gboolean         ret;
         GdmDisplay      *display = NULL;
         gboolean         is_initial = FALSE;
-        const char      *session_type;
         g_autofree gchar *preferred_display_server = NULL;
 
         g_return_val_if_fail (GDM_IS_LOCAL_DISPLAY_FACTORY (factory), FALSE);
@@ -451,6 +456,7 @@ gdm_local_display_factory_create_transient_display (Gd
         return ret;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 finish_display_on_seat_if_waiting (GdmDisplayStore *display_store,
                                    GdmDisplay      *display,
@@ -505,6 +511,7 @@ on_session_registered_cb (GObject *gobject,
 
         finish_waiting_displays_on_seat (factory, "seat0");
 }
+#endif
 
 static void
 on_display_status_changed (GdmDisplay             *display,
@@ -552,7 +559,7 @@ on_display_status_changed (GdmDisplay             *dis
                  * if there isn't one.
                  */
                 if (is_local &&
-                    (g_strcmp0 (session_class, "greeter") != 0 || factory->active_vt == GDM_INITIAL_VT)) {
+                    (g_strcmp0 (session_class, "greeter") != 0)) {
                         /* reset num failures */
                         factory->num_failures = 0;
 
@@ -741,7 +748,9 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
         const char *legacy_session_types[] = { "x11", NULL };
         GdmDisplayStore *store;
         GdmDisplay      *display = NULL;
+#ifdef WITH_SYSTEMD
         g_autofree char *login_session_id = NULL;
+#endif
         gboolean wayland_enabled = FALSE, xorg_enabled = FALSE;
         g_autofree gchar *preferred_display_server = NULL;
         gboolean falling_back = FALSE;
@@ -781,7 +790,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
                seat_supports_graphics = FALSE;
         }
 
-        if (g_strcmp0 (seat_id, "seat0") == 0) {
+        if (g_strcmp0 (seat_id, SEAT_ID) == 0) {
                 is_seat0 = TRUE;
 
                 falling_back = factory->num_failures > 0;
@@ -869,6 +878,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
                 return;
         }
 
+#ifdef WITH_SYSTEMD
         /* If we already have a login window, switch to it */
         if (gdm_get_login_window_session_id (seat_id, &login_session_id)) {
                 GdmDisplay *display;
@@ -886,6 +896,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
                         return;
                 }
         }
+#endif
 
         g_debug ("GdmLocalDisplayFactory: Adding display on seat %s", seat_id);
 
@@ -929,6 +940,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
         return;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 delete_display (GdmLocalDisplayFactory *factory,
                 const char             *seat_id) {
@@ -940,6 +952,7 @@ delete_display (GdmLocalDisplayFactory *factory,
         store = gdm_display_factory_get_display_store (GDM_DISPLAY_FACTORY (factory));
         gdm_display_store_foreach_remove (store, lookup_by_seat_id, (gpointer) seat_id);
 }
+#endif
 
 static gboolean
 gdm_local_display_factory_sync_seats (GdmLocalDisplayFactory *factory)
@@ -951,6 +964,8 @@ gdm_local_display_factory_sync_seats (GdmLocalDisplayF
         const char *seat;
 
         g_debug ("GdmLocalDisplayFactory: enumerating seats from logind");
+
+#ifdef WITH_SYSTEMD
         result = g_dbus_connection_call_sync (factory->connection,
                                               "org.freedesktop.login1",
                                               "/org/freedesktop/login1",
@@ -961,6 +976,18 @@ gdm_local_display_factory_sync_seats (GdmLocalDisplayF
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
@@ -980,6 +1007,7 @@ gdm_local_display_factory_sync_seats (GdmLocalDisplayF
         return TRUE;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 on_seat_new (GDBusConnection *connection,
              const gchar     *sender_name,
@@ -1093,6 +1121,7 @@ lookup_by_tty (const char *id,
 
         return g_strcmp0 (tty_to_check, tty_to_find) == 0;
 }
+#endif
 
 #if defined(ENABLE_USER_DISPLAY_SERVER)
 static void
@@ -1295,6 +1324,7 @@ on_uevent (GUdevClient *client,
 }
 #endif
 
+#ifdef WITH_SYSTEMD
 static void
 gdm_local_display_factory_start_monitor (GdmLocalDisplayFactory *factory)
 {
@@ -1352,10 +1382,12 @@ gdm_local_display_factory_start_monitor (GdmLocalDispl
         }
 #endif
 }
+#endif
 
 static void
 gdm_local_display_factory_stop_monitor (GdmLocalDisplayFactory *factory)
 {
+#ifdef HAVE_UDEV
         if (factory->uevent_handler_id) {
                 g_signal_handler_disconnect (factory->gudev_client, factory->uevent_handler_id);
                 factory->uevent_handler_id = 0;
@@ -1387,6 +1419,7 @@ gdm_local_display_factory_stop_monitor (GdmLocalDispla
                 factory->wait_to_finish_timeout_id = 0;
         }
 #endif
+#endif
 }
 
 static void
@@ -1441,7 +1474,9 @@ gdm_local_display_factory_start (GdmDisplayFactory *ba
                                  factory,
                                  0);
 
+#ifdef WITH_SYSTEMD
         gdm_local_display_factory_start_monitor (factory);
+#endif
         return gdm_local_display_factory_sync_seats (factory);
 }
 
