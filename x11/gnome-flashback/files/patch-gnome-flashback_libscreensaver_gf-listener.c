--- gnome-flashback/libscreensaver/gf-listener.c.orig	2023-08-12 06:50:17 UTC
+++ gnome-flashback/libscreensaver/gf-listener.c
@@ -26,16 +26,16 @@
 #include <gio/gunixfdlist.h>
 #include <time.h>
 
-#include "dbus/gf-login-manager-gen.h"
-#include "dbus/gf-login-session-gen.h"
+#include "dbus/gf-consolekit-manager-gen.h"
+#include "dbus/gf-consolekit-session-gen.h"
 #include "dbus/gf-screensaver-gen.h"
 #include "gf-screensaver-utils.h"
 
 #define SCREENSAVER_DBUS_NAME "org.gnome.ScreenSaver"
 #define SCREENSAVER_DBUS_PATH "/org/gnome/ScreenSaver"
 
-#define LOGIN_DBUS_NAME "org.freedesktop.login1"
-#define LOGIN_DBUS_PATH "/org/freedesktop/login1"
+#define LOGIN_DBUS_NAME "org.freedesktop.ConsoleKit"
+#define LOGIN_DBUS_PATH "/org/freedesktop/ConsoleKit/Manager"
 
 struct _GfListener
 {
@@ -45,8 +45,8 @@ struct _GfListener
   guint              screensaver_id;
 
   guint              login_id;
-  GfLoginSessionGen *login_session;
-  GfLoginManagerGen *login_manager;
+  GfConsoleKitSessionGen *login_session;
+  GfConsoleKitManagerGen *login_manager;
 
   gboolean           active;
   time_t             active_start;
@@ -80,7 +80,7 @@ release_inhibit_lock (GfListener *self)
   if (self->inhibit_lock_fd < 0)
     return;
 
-  g_debug ("Releasing systemd inhibit lock");
+  g_debug ("Releasing ConsoleKit2 inhibit lock");
 
   close (self->inhibit_lock_fd);
   self->inhibit_lock_fd = -1;
@@ -100,8 +100,8 @@ inhibit_cb (GObject      *object,
   error = NULL;
   pipe_fd = NULL;
 
-  gf_login_manager_gen_call_inhibit_finish (GF_LOGIN_MANAGER_GEN (object),
-                                            &pipe_fd, &fd_list, res, &error);
+  gf_console_kit_manager_gen_call_inhibit_finish (GF_CONSOLE_KIT_MANAGER_GEN (object),
+                                                  &pipe_fd, &fd_list, res, &error);
 
   if (error != NULL)
     {
@@ -135,16 +135,16 @@ take_inhibit_lock (GfListener *self)
   if (self->inhibit_lock_fd >= 0)
     return;
 
-  g_debug ("Taking systemd inhibit lock");
-  gf_login_manager_gen_call_inhibit (self->login_manager,
-                                     "sleep",
-                                     "GNOME Flashback",
-                                     "GNOME Flashback needs to lock the screen",
-                                     "delay",
-                                     NULL,
-                                     NULL,
-                                     inhibit_cb,
-                                     self);
+  g_debug ("Taking ConsoleKit2 inhibit lock");
+  gf_console_kit_manager_gen_call_inhibit (self->login_manager,
+                                           "sleep",
+                                           "GNOME Flashback",
+                                           "GNOME Flashback needs to lock the screen",
+                                           "delay",
+                                           NULL,
+                                           NULL,
+                                           inhibit_cb,
+                                           self);
 }
 
 static void
@@ -309,27 +309,27 @@ name_lost_handler (GDBusConnection *connection,
 }
 
 static void
-lock_cb (GfLoginSessionGen *login_session,
+lock_cb (GfConsoleKitSessionGen *login_session,
          GfListener        *self)
 {
-  g_debug ("systemd requested session lock");
+  g_debug ("ConsoleKit2 requested session lock");
   g_signal_emit (self, listener_signals[LOCK], 0);
 }
 
 static void
-unlock_cb (GfLoginSessionGen *login_session,
+unlock_cb (GfConsoleKitSessionGen *login_session,
            GfListener        *self)
 {
-  g_debug ("systemd requested session unlock");
+  g_debug ("ConsoleKit2 requested session unlock");
   gf_listener_set_active (self, FALSE);
 }
 
 static void
-notify_active_cb (GfLoginSessionGen *login_session,
+notify_active_cb (GfConsoleKitSessionGen *login_session,
                   GParamSpec        *pspec,
                   GfListener        *self)
 {
-  if (gf_login_session_gen_get_active (login_session))
+  if (gf_console_kit_session_gen_get_active (login_session))
     g_signal_emit (self, listener_signals[SIMULATE_USER_ACTIVITY], 0);
 }
 
@@ -339,11 +339,11 @@ login_session_ready_cb (GObject      *object,
                         gpointer      user_data)
 {
   GError *error;
-  GfLoginSessionGen *login_session;
+  GfConsoleKitSessionGen *login_session;
   GfListener *self;
 
   error = NULL;
-  login_session = gf_login_session_gen_proxy_new_for_bus_finish (res, &error);
+  login_session = gf_console_kit_session_gen_proxy_new_for_bus_finish (res, &error);
 
   if (error != NULL)
     {
@@ -365,9 +365,9 @@ login_session_ready_cb (GObject      *object,
   g_signal_connect (self->login_session, "notify::active",
                     G_CALLBACK (notify_active_cb), self);
 
-  if (gf_login_session_gen_get_locked_hint (self->login_session))
+  if (gf_console_kit_session_gen_get_locked_hint (self->login_session))
     {
-      g_debug ("systemd LockedHint=True");
+      g_debug ("ConsoleKit2 LockedHint=True");
       g_signal_emit (self, listener_signals[LOCK], 0);
     }
 }
@@ -383,10 +383,10 @@ get_session_cb (GObject      *object,
   object_path = NULL;
   error = NULL;
 
-  gf_login_manager_gen_call_get_session_finish (GF_LOGIN_MANAGER_GEN (object),
-                                                &object_path,
-                                                res,
-                                                &error);
+  gf_console_kit_manager_gen_call_get_session_for_cookie_finish (GF_CONSOLE_KIT_MANAGER_GEN (object),
+                                                                 &object_path,
+                                                                 res,
+                                                                 &error);
 
   if (error != NULL)
     {
@@ -397,19 +397,19 @@ get_session_cb (GObject      *object,
       return;
     }
 
-  gf_login_session_gen_proxy_new_for_bus (G_BUS_TYPE_SYSTEM,
-                                          G_DBUS_PROXY_FLAGS_NONE,
-                                          LOGIN_DBUS_NAME,
-                                          object_path,
-                                          NULL,
-                                          login_session_ready_cb,
-                                          user_data);
+  gf_console_kit_session_gen_proxy_new_for_bus (G_BUS_TYPE_SYSTEM,
+                                                G_DBUS_PROXY_FLAGS_NONE,
+                                                LOGIN_DBUS_NAME,
+                                                object_path,
+                                                NULL,
+                                                login_session_ready_cb,
+                                                user_data);
 
   g_free (object_path);
 }
 
 static void
-prepare_for_sleep_cb (GfLoginManagerGen *login_manager,
+prepare_for_sleep_cb (GfConsoleKitManagerGen *login_manager,
                       gboolean           start,
                       GfListener        *self)
 {
@@ -431,12 +431,12 @@ login_manager_ready_cb (GObject      *object,
                         gpointer      user_data)
 {
   GError *error;
-  GfLoginManagerGen *login_manager;
+  GfConsoleKitManagerGen *login_manager;
   GfListener *self;
   char *session_id;
 
   error = NULL;
-  login_manager = gf_login_manager_gen_proxy_new_for_bus_finish (res, &error);
+  login_manager = gf_console_kit_manager_gen_proxy_new_for_bus_finish (res, &error);
 
   if (error != NULL)
     {
@@ -460,11 +460,11 @@ login_manager_ready_cb (GObject      *object,
     {
       g_debug ("Session id: %s", session_id);
 
-      gf_login_manager_gen_call_get_session (self->login_manager,
-                                             session_id,
-                                             NULL,
-                                             get_session_cb,
-                                             self);
+      gf_console_kit_manager_gen_call_get_session_for_cookie (self->login_manager,
+                                                              session_id,
+                                                              NULL,
+                                                              get_session_cb,
+                                                              self);
 
       g_free (session_id);
     }
@@ -480,11 +480,11 @@ name_appeared_handler (GDBusConnection *connection,
                        const gchar     *name_owner,
                        gpointer         user_data)
 {
-  gf_login_manager_gen_proxy_new_for_bus (G_BUS_TYPE_SYSTEM,
-                                          G_DBUS_PROXY_FLAGS_NONE,
-                                          LOGIN_DBUS_NAME, LOGIN_DBUS_PATH,
-                                          NULL, login_manager_ready_cb,
-                                          user_data);
+  gf_console_kit_manager_gen_proxy_new_for_bus (G_BUS_TYPE_SYSTEM,
+                                                G_DBUS_PROXY_FLAGS_NONE,
+                                                LOGIN_DBUS_NAME, LOGIN_DBUS_PATH,
+                                                NULL, login_manager_ready_cb,
+                                                user_data);
 }
 
 static void
@@ -589,7 +589,7 @@ gf_listener_init (GfListener *self)
   self->inhibit_lock_fd = -1;
 
   /* check if logind is running */
-  if (access("/run/systemd/seats/", F_OK) >= 0)
+  if (access("/var/run/consolekit.pid", F_OK) >= 0)
     {
       self->login_id = g_bus_watch_name (G_BUS_TYPE_SYSTEM,
                                          LOGIN_DBUS_NAME,
@@ -654,8 +654,8 @@ gf_listener_set_active (GfListener *listener,
 
   if (listener->login_session)
     {
-      gf_login_session_gen_call_set_locked_hint (listener->login_session,
-                                                 active, NULL, NULL, NULL);
+      gf_console_kit_session_gen_call_set_locked_hint (listener->login_session,
+                                                       active, NULL, NULL, NULL);
     }
 
   gf_screensaver_gen_emit_active_changed (listener->screensaver, active);
