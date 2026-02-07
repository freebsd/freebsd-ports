--- modules/menu/gp-lock-logout.c.orig	2023-07-10 18:48:25 UTC
+++ modules/menu/gp-lock-logout.c
@@ -19,7 +19,7 @@
 #include "gp-lock-logout.h"
 
 #include "gp-dm-seat-gen.h"
-#include "gp-login1-manager-gen.h"
+#include "gp-consolekit-manager-gen.h"
 #include "gp-menu-utils.h"
 #include "gp-screensaver-gen.h"
 #include "gp-session-manager-gen.h"
@@ -38,7 +38,7 @@ struct _GpLockLogout
 
   GSettings           *lockdown;
 
-  GpLogin1ManagerGen  *login1_manager;
+  GpConsoleKitManagerGen  *login1_manager;
 
   GpSessionManagerGen *session_manager;
 
@@ -85,11 +85,11 @@ login1_manager_proxy_ready_cb (GObject      *source_ob
                                gpointer      user_data)
 {
   GError *error;
-  GpLogin1ManagerGen *manager;
+  GpConsoleKitManagerGen *manager;
   GpLockLogout *lock_logout;
 
   error = NULL;
-  manager = gp_login1_manager_gen_proxy_new_for_bus_finish (res, &error);
+  manager = gp_console_kit_manager_gen_proxy_new_for_bus_finish (res, &error);
 
   if (g_error_matches (error, G_IO_ERROR, G_IO_ERROR_CANCELLED))
     {
@@ -333,8 +333,8 @@ hibernate_cb (GObject      *source_object,
   GError *error;
 
   error = NULL;
-  gp_login1_manager_gen_call_hibernate_finish (GP_LOGIN1_MANAGER_GEN (source_object),
-                                               res, &error);
+  gp_console_kit_manager_gen_call_hibernate_finish (GP_CONSOLE_KIT_MANAGER_GEN (source_object),
+                                                    res, &error);
 
   if (g_error_matches (error, G_IO_ERROR, G_IO_ERROR_CANCELLED))
     {
@@ -344,7 +344,7 @@ hibernate_cb (GObject      *source_object,
 
   if (error)
     {
-      g_warning ("Could not ask login1 manager to hibernate: %s",
+      g_warning ("Could not ask ConsoleKit2 manager to hibernate: %s",
                  error->message);
 
       g_error_free (error);
@@ -356,9 +356,9 @@ static void
 hibernate_activate_cb (GtkWidget    *item,
                        GpLockLogout *lock_logout)
 {
-  gp_login1_manager_gen_call_hibernate (lock_logout->login1_manager,
-                                        TRUE, NULL, hibernate_cb,
-                                        lock_logout);
+  gp_console_kit_manager_gen_call_hibernate (lock_logout->login1_manager,
+                                             TRUE, NULL, hibernate_cb,
+                                             lock_logout);
 }
 
 static void
@@ -369,8 +369,8 @@ suspend_cb (GObject      *source_object,
   GError *error;
 
   error = NULL;
-  gp_login1_manager_gen_call_suspend_finish (GP_LOGIN1_MANAGER_GEN (source_object),
-                                             res, &error);
+  gp_console_kit_manager_gen_call_suspend_finish (GP_CONSOLE_KIT_MANAGER_GEN (source_object),
+                                                  res, &error);
 
   if (g_error_matches (error, G_IO_ERROR, G_IO_ERROR_CANCELLED))
     {
@@ -380,7 +380,7 @@ suspend_cb (GObject      *source_object,
 
   if (error)
     {
-      g_warning ("Could not ask login1 manager to suspend: %s",
+      g_warning ("Could not ask ConsoleKit2 manager to suspend: %s",
                  error->message);
 
       g_error_free (error);
@@ -392,9 +392,9 @@ static void
 suspend_activate_cb (GtkWidget    *item,
                      GpLockLogout *lock_logout)
 {
-  gp_login1_manager_gen_call_suspend (lock_logout->login1_manager,
-                                      TRUE, NULL, suspend_cb,
-                                      lock_logout);
+  gp_console_kit_manager_gen_call_suspend (lock_logout->login1_manager,
+                                           TRUE, NULL, suspend_cb,
+                                           lock_logout);
 }
 
 static void
@@ -405,8 +405,8 @@ hybrid_sleep_cb (GObject      *source_object,
   GError *error;
 
   error = NULL;
-  gp_login1_manager_gen_call_hybrid_sleep_finish (GP_LOGIN1_MANAGER_GEN (source_object),
-                                                  res, &error);
+  gp_console_kit_manager_gen_call_hybrid_sleep_finish (GP_CONSOLE_KIT_MANAGER_GEN (source_object),
+                                                       res, &error);
 
   if (g_error_matches (error, G_IO_ERROR, G_IO_ERROR_CANCELLED))
     {
@@ -416,7 +416,7 @@ hybrid_sleep_cb (GObject      *source_object,
 
   if (error)
     {
-      g_warning ("Could not ask login1 manager to hybrid sleep: %s",
+      g_warning ("Could not ask ConsoleKit2 manager to hybrid sleep: %s",
                  error->message);
 
       g_error_free (error);
@@ -428,9 +428,9 @@ static void
 hybrid_sleep_activate_cb (GtkWidget    *item,
                           GpLockLogout *lock_logout)
 {
-  gp_login1_manager_gen_call_hybrid_sleep (lock_logout->login1_manager,
-                                           TRUE, NULL, hybrid_sleep_cb,
-                                           lock_logout);
+  gp_console_kit_manager_gen_call_hybrid_sleep (lock_logout->login1_manager,
+                                                TRUE, NULL, hybrid_sleep_cb,
+                                                lock_logout);
 }
 
 static void
@@ -522,19 +522,19 @@ get_can_hibernate (GpLockLogout *lock_logout)
 
   if (!lock_logout->login1_manager)
     {
-      g_warning ("Login1 manager service not available.");
+      g_warning ("ConsoleKit2 manager service not available.");
       return FALSE;
     }
 
   error = NULL;
   result = NULL;
 
-  gp_login1_manager_gen_call_can_hibernate_sync (lock_logout->login1_manager,
-                                                 &result, NULL, &error);
+  gp_console_kit_manager_gen_call_can_hibernate_sync (lock_logout->login1_manager,
+                                                      &result, NULL, &error);
 
   if (error != NULL)
     {
-      g_warning ("Could not ask login1 manager if hibernate is available: %s",
+      g_warning ("Could not ask ConsoleKit2 manager if hibernate is available: %s",
                  error->message);
 
       g_error_free (error);
@@ -559,19 +559,19 @@ get_can_suspend (GpLockLogout *lock_logout)
 
   if (!lock_logout->login1_manager)
     {
-      g_warning ("Login1 manager service not available.");
+      g_warning ("ConsoleKit2 manager service not available.");
       return FALSE;
     }
 
   error = NULL;
   result = NULL;
 
-  gp_login1_manager_gen_call_can_suspend_sync (lock_logout->login1_manager,
-                                               &result, NULL, &error);
+  gp_console_kit_manager_gen_call_can_suspend_sync (lock_logout->login1_manager,
+                                                    &result, NULL, &error);
 
   if (error != NULL)
     {
-      g_warning ("Could not ask login1 manager if suspend is available: %s",
+      g_warning ("Could not ask ConsoleKit2 manager if suspend is available: %s",
                  error->message);
 
       g_error_free (error);
@@ -596,19 +596,19 @@ get_can_hybrid_sleep (GpLockLogout *lock_logout)
 
   if (!lock_logout->login1_manager)
     {
-      g_warning ("Login1 manager service not available.");
+      g_warning ("ConsoleKit2 manager service not available.");
       return FALSE;
     }
 
   error = NULL;
   result = NULL;
 
-  gp_login1_manager_gen_call_can_hybrid_sleep_sync (lock_logout->login1_manager,
-                                                    &result, NULL, &error);
+  gp_console_kit_manager_gen_call_can_hybrid_sleep_sync (lock_logout->login1_manager,
+                                                         &result, NULL, &error);
 
   if (error != NULL)
     {
-      g_warning ("Could not ask login1 manager if hybrid sleep is available: %s",
+      g_warning ("Could not ask ConsoleKit2 manager if hybrid sleep is available: %s",
                  error->message);
 
       g_error_free (error);
@@ -744,13 +744,13 @@ gp_lock_logout_constructed (GObject *object)
   g_signal_connect (lock_logout->lockdown, "changed",
                     G_CALLBACK (lockdown_changed_cb), lock_logout);
 
-  gp_login1_manager_gen_proxy_new_for_bus (G_BUS_TYPE_SYSTEM,
-                                           G_DBUS_PROXY_FLAGS_NONE,
-                                           "org.freedesktop.login1",
-                                           "/org/freedesktop/login1",
-                                           NULL,
-                                           login1_manager_proxy_ready_cb,
-                                           lock_logout);
+  gp_console_kit_manager_gen_proxy_new_for_bus (G_BUS_TYPE_SYSTEM,
+                                                G_DBUS_PROXY_FLAGS_NONE,
+                                                "org.freedesktop.ConsoleKit",
+                                                "/org/freedesktop/ConsoleKit/Manager",
+                                                NULL,
+                                                login1_manager_proxy_ready_cb,
+                                                lock_logout);
 
   gp_session_manager_gen_proxy_new_for_bus (G_BUS_TYPE_SESSION,
                                             G_DBUS_PROXY_FLAGS_NONE,
