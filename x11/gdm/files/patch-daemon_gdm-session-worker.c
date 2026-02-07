--- daemon/gdm-session-worker.c.orig	2024-09-16 13:28:26 UTC
+++ daemon/gdm-session-worker.c
@@ -28,9 +28,11 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#ifdef WITH_SYSTEMD
 #include <sys/ioctl.h>
 #include <sys/vt.h>
 #include <sys/kd.h>
+#endif
 #include <errno.h>
 #include <grp.h>
 #include <pwd.h>
@@ -53,8 +55,10 @@
 #include <X11/Xauth.h>
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
 #include <systemd/sd-login.h>
+#endif
 
 #ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
@@ -130,6 +134,10 @@ struct _GdmSessionWorker
 
         int               exit_code;
 
+#ifdef WITH_CONSOLE_KIT
+        char             *session_cookie;
+#endif
+
         pam_handle_t     *pam_handle;
 
         GPid              child_pid;
@@ -144,6 +152,11 @@ struct _GdmSessionWorker
         char             *hostname;
         char             *username;
         char             *log_file;
+#ifdef WITH_CONSOLE_KIT
+        char             *session_type;
+        char             *session_class;
+        char             *session_service;
+#endif
         char             *session_id;
         uid_t             uid;
         gid_t             gid;
@@ -213,12 +226,223 @@ typedef int (* GdmSessionWorkerPamNewMessagesFunc) (in
                                                     struct pam_response **,
                                                     gpointer);
 
+#ifdef WITH_CONSOLE_KIT
+static char *
+gdm_session_worker_get_environment_variable (GdmSessionWorker *worker,
+                                             const char       *key);
+#endif
+
 G_DEFINE_TYPE_WITH_CODE (GdmSessionWorker,
                          gdm_session_worker,
                          GDM_DBUS_TYPE_WORKER_SKELETON,
                          G_IMPLEMENT_INTERFACE (GDM_DBUS_TYPE_WORKER,
                                                 worker_interface_init))
 
+#ifdef WITH_CONSOLE_KIT
+static gboolean
+open_ck_session (GdmSessionWorker  *worker)
+{
+        GDBusConnection  *system_bus;
+        GVariantBuilder   builder;
+        GVariant         *parameters;
+        GVariant         *in_args;
+        struct passwd    *pwent;
+        GVariant         *reply;
+        GError           *error = NULL;
+        const char       *display_name;
+        const char       *display_device;
+        const char       *display_hostname;
+        gint32            uid;
+
+        g_assert (worker->session_cookie == NULL);
+
+        if (worker->x11_display_name != NULL) {
+                display_name = worker->x11_display_name;
+        } else {
+                display_name = "";
+        }
+        if (worker->hostname != NULL) {
+                display_hostname = worker->hostname;
+        } else {
+                display_hostname = "";
+        }
+        if (worker->display_device != NULL) {
+                display_device = worker->display_device;
+        } else {
+                display_device = "";
+        }
+
+        g_assert (worker->username != NULL);
+
+        gdm_get_pwent_for_name (worker->username, &pwent);
+        if (pwent == NULL) {
+                goto out;
+        }
+
+        uid = (gint32) pwent->pw_uid;
+
+        error = NULL;
+        system_bus = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &error);
+
+        if (system_bus == NULL) {
+                g_warning ("Couldn't create connection to system bus: %s",
+                           error->message);
+
+                g_error_free (error);
+                goto out;
+        }
+
+        g_variant_builder_init (&builder, G_VARIANT_TYPE ("a(sv)"));
+        g_variant_builder_add_parsed (&builder, "('unix-user', <%i>)", uid);
+        g_variant_builder_add_parsed (&builder, "('x11-display-device', <%s>)", display_device);
+        g_variant_builder_add_parsed (&builder, "('x11-display', <%s>)", display_name);
+        g_variant_builder_add_parsed (&builder, "('remote-host-name', <%s>)", display_hostname);
+        g_variant_builder_add_parsed (&builder, "('is-local', <%b>)", worker->display_is_local);
+
+        worker->session_type = gdm_session_worker_get_environment_variable (worker, "XDG_SESSION_TYPE");
+        if (worker->session_type != NULL) {
+                g_variant_builder_add_parsed (&builder, "('session-type', <%s>)", worker->session_type);
+        }
+
+        worker->session_class = gdm_session_worker_get_environment_variable (worker, "XDG_SESSION_CLASS");
+        if (worker->session_class != NULL) {
+                g_variant_builder_add_parsed (&builder, "('session-class', <%s>)", worker->session_class);
+        }
+
+        worker->session_service = gdm_session_worker_get_environment_variable (worker, "XDG_SESSION_SERVICE");
+        if (worker->session_service != NULL) {
+                g_variant_builder_add_parsed (&builder, "('session-service', <%s>)", worker->session_service);
+        }
+
+        parameters = g_variant_builder_end (&builder);
+        in_args = g_variant_new_tuple (&parameters, 1);
+
+        reply = g_dbus_connection_call_sync (system_bus,
+                                             CK_NAME,
+                                             CK_MANAGER_PATH,
+                                             CK_MANAGER_INTERFACE,
+                                             "OpenSessionWithParameters",
+                                             in_args,
+                                             G_VARIANT_TYPE ("(s)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL,
+                                             &error);
+
+        if (! reply) {
+                g_warning ("%s\n", error->message);
+                g_clear_error (&error);
+                goto out;
+        }
+
+        g_variant_get (reply, "(s)", &worker->session_cookie);
+
+        g_variant_unref (reply);
+
+out:
+        return worker->session_cookie != NULL;
+}
+
+static void
+close_ck_session (GdmSessionWorker *worker)
+{
+        GDBusConnection  *system_bus;
+        GVariant         *reply;
+        GError           *error = NULL;
+        gboolean          was_closed;
+
+        if (worker->session_cookie == NULL) {
+                return;
+        }
+
+        error = NULL;
+        system_bus = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &error);
+
+        if (system_bus == NULL) {
+                g_warning ("Couldn't create connection to system bus: %s",
+                           error->message);
+
+                g_error_free (error);
+                goto out;
+        }
+
+        reply = g_dbus_connection_call_sync (system_bus,
+                                             CK_NAME,
+                                             CK_MANAGER_PATH,
+                                             CK_MANAGER_INTERFACE,
+                                             "CloseSession",
+                                             g_variant_new ("(s)", worker->session_cookie),
+                                             G_VARIANT_TYPE ("(b)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL,
+                                             &error);
+
+        if (! reply) {
+                g_warning ("%s", error->message);
+                g_clear_error (&error);
+                goto out;
+        }
+
+        g_variant_get (reply, "(b)", &was_closed);
+
+        if (!was_closed) {
+                g_warning ("Unable to close ConsoleKit session");
+        }
+
+        g_variant_unref (reply);
+
+out:
+        g_clear_pointer (&worker->session_cookie,
+                         (GDestroyNotify) g_free);
+}
+
+static char *
+get_ck_session_id (GdmSessionWorker *worker)
+{
+        GDBusConnection  *system_bus;
+        GVariant         *reply;
+        GError           *error = NULL;
+        char             *session_id = NULL;
+
+        error = NULL;
+        system_bus = g_bus_get_sync (G_BUS_TYPE_SYSTEM, NULL, &error);
+
+        if (system_bus == NULL) {
+                g_warning ("Couldn't create connection to system bus: %s",
+                           error->message);
+
+                g_error_free (error);
+                goto out;
+        }
+
+        reply = g_dbus_connection_call_sync (system_bus,
+                                             CK_NAME,
+                                             CK_MANAGER_PATH,
+                                             CK_MANAGER_INTERFACE,
+                                             "GetSessionForCookie",
+                                             g_variant_new ("(s)", worker->session_cookie),
+                                             G_VARIANT_TYPE ("(o)"),
+                                             G_DBUS_CALL_FLAGS_NONE,
+                                             -1,
+                                             NULL,
+                                             &error);
+
+        if (reply == NULL) {
+                g_warning ("%s", error->message);
+                g_clear_error (&error);
+                goto out;
+        }
+
+        g_variant_get (reply, "(o)", &session_id);
+
+        g_variant_unref (reply);
+
+out:
+        return session_id;
+}
+#endif
+
 /* adapted from glib script_execute */
 static void
 script_execute (const gchar *file,
@@ -972,6 +1196,7 @@ gdm_session_worker_stop_auditor (GdmSessionWorker *wor
         worker->auditor = NULL;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 on_release_display (int signal)
 {
@@ -1114,6 +1339,7 @@ jump_to_vt (GdmSessionWorker  *worker,
 
         close (active_vt_tty_fd);
 }
+#endif
 
 static void
 gdm_session_worker_set_state (GdmSessionWorker      *worker,
@@ -1216,7 +1442,9 @@ gdm_session_worker_initialize_pam (GdmSessionWorker   
 {
         struct pam_conv        pam_conversation;
         int                    error_code;
+#ifdef WITH_SYSTEMD
         char tty_string[256];
+#endif
 
         g_assert (service != NULL);
         g_assert (worker->pam_handle == NULL);
@@ -1297,6 +1525,10 @@ gdm_session_worker_initialize_pam (GdmSessionWorker   
                 gdm_session_worker_set_environment_variable (worker, "XDG_SEAT", seat_id);
         }
 
+#ifdef WITH_CONSOLE_KIT
+        gdm_session_worker_set_environment_variable (worker, "XDG_SESSION_SERVICE", service);
+#endif
+
         if (strcmp (service, "gdm-launch-environment") == 0) {
                 gdm_session_worker_set_environment_variable (worker, "XDG_SESSION_CLASS", "greeter");
         }
@@ -1304,13 +1536,6 @@ gdm_session_worker_initialize_pam (GdmSessionWorker   
         g_debug ("GdmSessionWorker: state SETUP_COMPLETE");
         gdm_session_worker_set_state (worker, GDM_SESSION_WORKER_STATE_SETUP_COMPLETE);
 
-        if (g_strcmp0 (seat_id, "seat0") == 0 && worker->seat0_has_vts) {
-                /* Temporarily set PAM_TTY with the login VT,
-                   PAM_TTY will be reset with the users VT right before the user session is opened */
-                g_snprintf (tty_string, 256, "/dev/tty%d", GDM_INITIAL_VT);
-                pam_set_item (worker->pam_handle, PAM_TTY, tty_string);
-        }
-
         if (!display_is_local)
                 worker->password_is_required = TRUE;
 
@@ -1621,7 +1846,11 @@ _lookup_passwd_info (const char *username,
                 if (passwd_entry->pw_shell != NULL && passwd_entry->pw_shell[0] != '\0') {
                         *shellp = g_strdup (passwd_entry->pw_shell);
                 } else {
+#if defined(__FreeBSD__)
+                        *shellp = g_strdup ("/bin/sh");
+#else
                         *shellp = g_strdup ("/bin/bash");
+#endif
                 }
         }
         ret = TRUE;
@@ -1760,6 +1989,20 @@ gdm_session_worker_get_environment (GdmSessionWorker *
         return (const char * const *) pam_getenvlist (worker->pam_handle);
 }
 
+#ifdef WITH_CONSOLE_KIT
+static void
+register_ck_session (GdmSessionWorker *worker)
+{
+        open_ck_session (worker);
+
+        if (worker->session_cookie != NULL) {
+                gdm_session_worker_set_environment_variable (worker,
+                                                             "XDG_SESSION_COOKIE",
+                                                             worker->session_cookie);
+        }
+}
+#endif
+
 static gboolean
 run_script (GdmSessionWorker *worker,
             const char       *dir)
@@ -1837,6 +2080,10 @@ session_worker_child_watch (GPid              pid,
                  : WIFSIGNALED (status) ? WTERMSIG (status)
                  : -1);
 
+#ifdef WITH_CONSOLE_KIT
+        close_ck_session (worker);
+#endif
+
         gdm_session_worker_uninitialize_pam (worker, PAM_SUCCESS);
 
         worker->child_pid = -1;
@@ -2037,6 +2284,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
 
         error_code = PAM_SUCCESS;
 
+#ifdef WITH_SYSTEMD
         /* If we're in new vt mode, jump to the new vt now. There's no need to jump for
          * the other two modes: in the logind case, the session will activate itself when
          * ready, and in the reuse server case, we're already on the correct VT. */
@@ -2045,6 +2293,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
                         jump_to_vt (worker, worker->session_vt);
                 }
         }
+#endif
 
         if (!worker->is_program_session && !run_script (worker, GDMCONFDIR "/PostLogin")) {
                 g_set_error (error,
@@ -2107,6 +2356,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
                         _exit (EXIT_FAILURE);
                 }
 
+#ifdef WITH_SYSTEMD
                 /* Take control of the tty
                  */
                 if (needs_controlling_terminal) {
@@ -2114,6 +2364,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
                                 g_debug ("GdmSessionWorker: could not take control of tty: %m");
                         }
                 }
+#endif
 
 #ifdef HAVE_LOGINCAP
                 if (setusercontext (NULL, passwd_entry, passwd_entry->pw_uid, LOGIN_SETALL) < 0) {
@@ -2242,6 +2493,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
         return TRUE;
 }
 
+#ifdef WITH_SYSTEMD
 static gboolean
 set_up_for_new_vt (GdmSessionWorker *worker)
 {
@@ -2341,6 +2593,7 @@ fail:
         close (fd);
         return FALSE;
 }
+#endif
 
 static gboolean
 set_up_for_current_vt (GdmSessionWorker  *worker,
@@ -2410,12 +2663,14 @@ set_up_for_current_vt (GdmSessionWorker  *worker,
          }
 #endif
 
+#ifdef WITH_SYSTEMD
         if (g_strcmp0 (worker->display_seat_id, "seat0") == 0 && worker->seat0_has_vts) {
                 g_debug ("GdmSessionWorker: setting XDG_VTNR to current vt");
                 set_xdg_vtnr_to_current_vt (worker);
         } else {
                 g_debug ("GdmSessionWorker: not setting XDG_VTNR since no VTs on seat");
         }
+#endif
 
         return TRUE;
 }
@@ -2440,6 +2695,7 @@ gdm_session_worker_open_session (GdmSessionWorker  *wo
                         break;
                 case GDM_SESSION_DISPLAY_MODE_NEW_VT:
                 case GDM_SESSION_DISPLAY_MODE_LOGIND_MANAGED:
+#ifdef WITH_SYSTEMD
                         if (!set_up_for_new_vt (worker)) {
                                 g_set_error (error,
                                              GDM_SESSION_WORKER_ERROR,
@@ -2447,6 +2703,7 @@ gdm_session_worker_open_session (GdmSessionWorker  *wo
                                              "Unable to open VT");
                                 return FALSE;
                         }
+#endif
                         break;
                 }
         }
@@ -2470,8 +2727,16 @@ gdm_session_worker_open_session (GdmSessionWorker  *wo
         g_debug ("GdmSessionWorker: state SESSION_OPENED");
         gdm_session_worker_set_state (worker, GDM_SESSION_WORKER_STATE_SESSION_OPENED);
 
+#if defined(WITH_SYSTEMD)
         session_id = gdm_session_worker_get_environment_variable (worker, "XDG_SESSION_ID");
+#elif defined(WITH_CONSOLE_KIT)
+        register_ck_session (worker);
 
+        if (session_id == NULL) {
+                session_id = get_ck_session_id (worker);
+        }
+#endif
+
         if (session_id != NULL) {
                 g_free (worker->session_id);
                 worker->session_id = g_steal_pointer (&session_id);
@@ -3022,6 +3287,7 @@ gdm_session_worker_handle_open (GdmDBusWorker         
         return TRUE;
 }
 
+#ifdef SUPPORTS_PAM_EXTENSIONS
 static char **
 filter_extensions (const char * const *extensions)
 {
@@ -3045,6 +3311,7 @@ filter_extensions (const char * const *extensions)
 
         return g_steal_pointer (&filtered_extensions);
 }
+#endif
 
 static gboolean
 gdm_session_worker_handle_initialize (GdmDBusWorker         *object,
@@ -3064,8 +3331,10 @@ gdm_session_worker_handle_initialize (GdmDBusWorker   
         while (g_variant_iter_loop (&iter, "{sv}", &key, &value)) {
                 if (g_strcmp0 (key, "service") == 0) {
                         worker->service = g_variant_dup_string (value, NULL);
+#ifdef SUPPORTS_PAM_EXTENSIONS
                 } else if (g_strcmp0 (key, "extensions") == 0) {
                         worker->extensions = filter_extensions (g_variant_get_strv (value, NULL));
+#endif
                 } else if (g_strcmp0 (key, "username") == 0) {
                         worker->username = g_variant_dup_string (value, NULL);
                 } else if (g_strcmp0 (key, "is-program-session") == 0) {
@@ -3089,7 +3358,9 @@ gdm_session_worker_handle_initialize (GdmDBusWorker   
                 }
         }
 
+#ifdef WITH_SYSTEMD
         worker->seat0_has_vts = sd_seat_can_tty ("seat0");
+#endif
 
         worker->pending_invocation = invocation;
 
