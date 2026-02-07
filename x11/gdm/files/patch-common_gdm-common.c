--- common/gdm-common.c.orig	2023-09-14 15:27:04 UTC
+++ common/gdm-common.c
@@ -36,8 +36,13 @@
 
 #include "gdm-common.h"
 
+#if defined(WITH_SYSTEMD)
 #include <systemd/sd-login.h>
+#elif defined(WITH_CONSOLE_KIT)
+#include <ConsoleKit/sd-login.h>
+#endif
 
+
 #define GDM_DBUS_NAME                            "org.gnome.DisplayManager"
 #define GDM_DBUS_LOCAL_DISPLAY_FACTORY_PATH      "/org/gnome/DisplayManager/LocalDisplayFactory"
 #define GDM_DBUS_LOCAL_DISPLAY_FACTORY_INTERFACE "org.gnome.DisplayManager.LocalDisplayFactory"
@@ -368,15 +373,22 @@ gdm_activate_session_by_id (GDBusConnection *connectio
         g_return_val_if_fail (session_id != NULL, FALSE);
 
         reply = g_dbus_connection_call_sync (connection,
+#if defined(WITH_SYSTEMD)
                                              "org.freedesktop.login1",
                                              "/org/freedesktop/login1",
                                              "org.freedesktop.login1.Manager",
+#elif defined(WITH_CONSOLE_KIT)
+                                             "org.freedesktop.ConsoleKit",
+                                             "/org/freedesktop/ConsoleKit/Manager",
+                                             "org.freedesktop.ConsoleKit.Manager",
+#endif
                                              "ActivateSessionOnSeat",
                                              g_variant_new ("(ss)", session_id, seat_id),
                                              NULL,
                                              G_DBUS_CALL_FLAGS_NONE,
                                              -1,
                                              cancellable, &local_error);
+
         if (reply == NULL) {
                 g_warning ("Unable to activate session: %s", local_error->message);
                 g_error_free (local_error);
@@ -916,7 +928,9 @@ gdm_find_display_session (GPid        pid,
 
                 return TRUE;
         } else {
+#ifdef ENODATA
                 if (res != -ENODATA)
+#endif
                         g_warning ("GdmCommon: Failed to retrieve session information for pid %d: %s",
                                    pid, strerror (-res));
         }
