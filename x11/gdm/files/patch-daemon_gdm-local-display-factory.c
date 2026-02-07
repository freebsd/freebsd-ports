--- daemon/gdm-local-display-factory.c.orig	2024-09-16 13:28:26 UTC
+++ daemon/gdm-local-display-factory.c
@@ -28,11 +28,15 @@
 #include <glib-object.h>
 #include <gio/gio.h>
 
+#ifdef WITH_SYSTEMD
 #ifdef HAVE_UDEV
 #include <gudev/gudev.h>
 #endif
 
 #include <systemd/sd-login.h>
+#elif defined(WITH_CONSOLE_KIT)
+#include <ConsoleKit/sd-login.h>
+#endif
 
 #include "gdm-common.h"
 #include "gdm-manager.h"
@@ -68,8 +72,10 @@ struct _GdmLocalDisplayFactory
         /* FIXME: this needs to be per seat? */
         guint            num_failures;
 
+#ifdef WITH_SYSTEMD
         guint            seat_new_id;
         guint            seat_removed_id;
+#endif
         guint            seat_properties_changed_id;
         guint            seat_attention_key;
 
@@ -108,9 +114,11 @@ static gpointer local_display_factory_object = NULL;
 
 static gboolean gdm_local_display_factory_sync_seats    (GdmLocalDisplayFactory *factory);
 static gpointer local_display_factory_object = NULL;
+#ifdef WITH_SYSTEMD
 static gboolean lookup_by_session_id (const char *id,
                                       GdmDisplay *display,
                                       gpointer    user_data);
+#endif
 
 G_DEFINE_TYPE (GdmLocalDisplayFactory, gdm_local_display_factory, GDM_TYPE_DISPLAY_FACTORY)
 
@@ -474,6 +482,7 @@ gdm_local_display_factory_create_transient_display (Gd
         return ret;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 finish_display_on_seat_if_waiting (GdmDisplayStore *display_store,
                                    GdmDisplay      *display,
@@ -528,6 +537,7 @@ on_session_registered_cb (GObject *gobject,
 
         finish_waiting_displays_on_seat (factory, "seat0");
 }
+#endif
 
 static void
 on_display_status_changed (GdmDisplay             *display,
@@ -560,7 +570,9 @@ on_display_status_changed (GdmDisplay             *dis
                       "session-id", &session_id,
                       NULL);
 
+#ifdef WITH_SYSTEMD
         sd_seat_get_active (seat_id, &seat_active_session, NULL);
+#endif
 
         status = gdm_display_get_status (display);
 
@@ -578,12 +590,16 @@ on_display_status_changed (GdmDisplay             *dis
                  * screen when the user logs out.
                  */
                 if (is_local &&
+#ifdef WITH_SYSTEMD
                     ((g_strcmp0 (session_class, "greeter") != 0 &&
                       (!seat_active_session || g_strcmp0(session_id, seat_active_session) == 0)) ||
 #if defined(ENABLE_USER_DISPLAY_SERVER)
                      (g_strcmp0 (seat_id, "seat0") == 0 && factory->active_vt == GDM_INITIAL_VT) ||
 #endif
                      g_strcmp0 (seat_id, "seat0") != 0)) {
+#else
+                    (g_strcmp0 (session_class, "greeter") != 0)) {
+#endif
                         /* reset num failures */
                         factory->num_failures = 0;
 
@@ -818,12 +834,15 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
         g_auto (GStrv) session_types = NULL;
         const char *legacy_session_types[] = { "x11", NULL };
         GdmDisplay      *display = NULL;
+#ifdef WITH_SYSTEMD
         g_autofree char *login_session_id = NULL;
+#endif
         g_autofree gchar *preferred_display_server = NULL;
         gboolean waiting_on_udev = FALSE;
 
         g_debug ("GdmLocalDisplayFactory: display for seat %s requested", seat_id);
 
+#ifdef WITH_SYSTEMD
         /* If we already have a login window, switch to it */
         if (gdm_get_login_window_session_id (seat_id, &login_session_id)) {
                 GdmDisplay *display;
@@ -843,6 +862,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
                         return;
                 }
         }
+#endif
 
         preferred_display_server = get_preferred_display_server (factory);
 
@@ -993,6 +1013,7 @@ ensure_display_for_seat (GdmLocalDisplayFactory *facto
         return;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 delete_display (GdmLocalDisplayFactory *factory,
                 const char             *seat_id) {
@@ -1004,6 +1025,7 @@ delete_display (GdmLocalDisplayFactory *factory,
         store = gdm_display_factory_get_display_store (GDM_DISPLAY_FACTORY (factory));
         gdm_display_store_foreach_remove (store, lookup_by_seat_id, (gpointer) seat_id);
 }
+#endif
 
 static gboolean
 gdm_local_display_factory_sync_seats (GdmLocalDisplayFactory *factory)
@@ -1015,6 +1037,7 @@ gdm_local_display_factory_sync_seats (GdmLocalDisplayF
         const char *seat;
 
         g_debug ("GdmLocalDisplayFactory: enumerating seats from logind");
+#ifdef WITH_SYSTEMD
         result = g_dbus_connection_call_sync (factory->connection,
                                               "org.freedesktop.login1",
                                               "/org/freedesktop/login1",
@@ -1025,6 +1048,18 @@ gdm_local_display_factory_sync_seats (GdmLocalDisplayF
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
@@ -1044,6 +1079,7 @@ gdm_local_display_factory_sync_seats (GdmLocalDisplayF
         return TRUE;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 on_seat_activate_greeter (GDBusConnection *connection,
                           const gchar     *sender_name,
@@ -1177,6 +1213,7 @@ lookup_by_tty (const char *id,
 
         return g_strcmp0 (tty_to_check, tty_to_find) == 0;
 }
+#endif
 
 #if defined(ENABLE_USER_DISPLAY_SERVER)
 static void
@@ -1354,6 +1391,7 @@ on_vt_changed (GIOChannel    *source,
 }
 #endif
 
+#ifdef WITH_SYSTEMD
 #ifdef HAVE_UDEV
 static void
 on_uevent (GUdevClient *client,
@@ -1444,10 +1482,12 @@ gdm_local_display_factory_start_monitor (GdmLocalDispl
         }
 #endif
 }
+#endif
 
 static void
 gdm_local_display_factory_stop_monitor (GdmLocalDisplayFactory *factory)
 {
+#ifdef WITH_SYSTEMD
         if (factory->uevent_handler_id) {
                 g_signal_handler_disconnect (factory->gudev_client, factory->uevent_handler_id);
                 factory->uevent_handler_id = 0;
@@ -1478,6 +1518,7 @@ gdm_local_display_factory_stop_monitor (GdmLocalDispla
         g_clear_handle_id (&factory->active_vt_watch_id, g_source_remove);
         g_clear_handle_id (&factory->wait_to_finish_timeout_id, g_source_remove);
 #endif
+#endif
 }
 
 static void
@@ -1532,7 +1573,9 @@ gdm_local_display_factory_start (GdmDisplayFactory *ba
                                  factory,
                                  0);
 
+#ifdef WITH_SYSTEMD
         gdm_local_display_factory_start_monitor (factory);
+#endif
         return gdm_local_display_factory_sync_seats (factory);
 }
 
