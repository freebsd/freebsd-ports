--- daemon/gdm-session-worker.c.orig	2022-01-12 14:15:56 UTC
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
@@ -49,7 +51,9 @@
 
 #include <X11/Xauth.h>
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
@@ -94,7 +98,7 @@
 #endif
 
 #ifndef GDM_SESSION_DEFAULT_PATH
-#define GDM_SESSION_DEFAULT_PATH "/usr/local/bin:/usr/bin:/bin"
+#define GDM_SESSION_DEFAULT_PATH "%%LOCALBASE%%/bin:/usr/bin:/bin"
 #endif
 
 #ifndef GDM_SESSION_ROOT_UID
@@ -126,6 +130,10 @@ struct GdmSessionWorkerPrivate
 
         int               exit_code;
 
+#ifdef WITH_CONSOLE_KIT
+        char             *session_cookie;
+#endif
+
         pam_handle_t     *pam_handle;
 
         GPid              child_pid;
@@ -140,6 +148,11 @@ struct GdmSessionWorkerPrivate
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
@@ -207,6 +220,12 @@ typedef int (* GdmSessionWorkerPamNewMessagesFunc) (in
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
@@ -214,6 +233,211 @@ G_DEFINE_TYPE_WITH_CODE (GdmSessionWorker,
                                                 worker_interface_init)
                          G_ADD_PRIVATE (GdmSessionWorker))
 
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
+        g_assert (worker->priv->session_cookie == NULL);
+
+        if (worker->priv->x11_display_name != NULL) {
+                display_name = worker->priv->x11_display_name;
+        } else {
+                display_name = "";
+        }
+        if (worker->priv->hostname != NULL) {
+                display_hostname = worker->priv->hostname;
+        } else {
+                display_hostname = "";
+        }
+        if (worker->priv->display_device != NULL) {
+                display_device = worker->priv->display_device;
+        } else {
+                display_device = "";
+        }
+
+        g_assert (worker->priv->username != NULL);
+
+        gdm_get_pwent_for_name (worker->priv->username, &pwent);
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
+        g_variant_builder_add_parsed (&builder, "('is-local', <%b>)", worker->priv->display_is_local);
+
+        worker->priv->session_type = gdm_session_worker_get_environment_variable (worker, "XDG_SESSION_TYPE");
+        if (worker->priv->session_type != NULL) {
+                g_variant_builder_add_parsed (&builder, "('session-type', <%s>)", worker->priv->session_type);
+        }
+
+        worker->priv->session_class = gdm_session_worker_get_environment_variable (worker, "XDG_SESSION_CLASS");
+        if (worker->priv->session_class != NULL) {
+                g_variant_builder_add_parsed (&builder, "('session-class', <%s>)", worker->priv->session_class);
+        }
+
+        worker->priv->session_service = gdm_session_worker_get_environment_variable (worker, "XDG_SESSION_SERVICE");
+        if (worker->priv->session_service != NULL) {
+                g_variant_builder_add_parsed (&builder, "('session-service', <%s>)", worker->priv->session_service);
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
+        g_variant_get (reply, "(s)", &worker->priv->session_cookie);
+
+        g_variant_unref (reply);
+
+out:
+        return worker->priv->session_cookie != NULL;
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
+        if (worker->priv->session_cookie == NULL) {
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
+                                             g_variant_new ("(s)", worker->priv->session_cookie),
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
+        g_clear_pointer (&worker->priv->session_cookie,
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
+                                             g_variant_new ("(s)", worker->priv->session_cookie),
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
@@ -670,7 +894,9 @@ gdm_session_worker_process_pam_message (GdmSessionWork
         char    *user_answer;
         gboolean res;
         char    *utf8_msg;
+#ifdef PAM_RADIO_TYPE
         char	*msg;
+#endif
 
         if (response != NULL) {
                 *response = NULL;
@@ -914,6 +1140,7 @@ gdm_session_worker_stop_auditor (GdmSessionWorker *wor
         worker->priv->auditor = NULL;
 }
 
+#ifdef WITH_SYSTEMD
 static void
 on_release_display (int signal)
 {
@@ -1056,6 +1283,7 @@ jump_to_vt (GdmSessionWorker  *worker,
 
         close (active_vt_tty_fd);
 }
+#endif
 
 static void
 gdm_session_worker_set_state (GdmSessionWorker      *worker,
@@ -1158,7 +1386,9 @@ gdm_session_worker_initialize_pam (GdmSessionWorker   
 {
         struct pam_conv        pam_conversation;
         int                    error_code;
+#ifdef WITH_SYSTEMD
         char tty_string[256];
+#endif
 
         g_assert (worker->priv->pam_handle == NULL);
 
@@ -1230,6 +1460,10 @@ gdm_session_worker_initialize_pam (GdmSessionWorker   
                 gdm_session_worker_set_environment_variable (worker, "XDG_SEAT", seat_id);
         }
 
+#ifdef WITH_CONSOLE_KIT
+        gdm_session_worker_set_environment_variable (worker, "XDG_SESSION_SERVICE", service);
+#endif
+
         if (strcmp (service, "gdm-launch-environment") == 0) {
                 gdm_session_worker_set_environment_variable (worker, "XDG_SESSION_CLASS", "greeter");
         }
@@ -1237,12 +1471,14 @@ gdm_session_worker_initialize_pam (GdmSessionWorker   
         g_debug ("GdmSessionWorker: state SETUP_COMPLETE");
         gdm_session_worker_set_state (worker, GDM_SESSION_WORKER_STATE_SETUP_COMPLETE);
 
+#ifdef WITH_SYSTEMD
         /* Temporarily set PAM_TTY with the login VT,
            PAM_TTY will be reset with the users VT right before the user session is opened */
         g_snprintf (tty_string, 256, "/dev/tty%d", GDM_INITIAL_VT);
         pam_set_item (worker->priv->pam_handle, PAM_TTY, tty_string);
         if (!display_is_local)
                 worker->priv->password_is_required = TRUE;
+#endif
 
  out:
         if (error_code != PAM_SUCCESS) {
@@ -1545,7 +1781,11 @@ _lookup_passwd_info (const char *username,
                 if (passwd_entry->pw_shell != NULL && passwd_entry->pw_shell[0] != '\0') {
                         *shellp = g_strdup (passwd_entry->pw_shell);
                 } else {
-                        *shellp = g_strdup ("/bin/bash");
+#if defined(__OpenBSD__)
+                        *shellp = g_strdup ("/bin/ksh");
+#else
+                        *shellp = g_strdup ("/bin/sh");
+#endif
                 }
         }
         ret = TRUE;
@@ -1689,6 +1929,20 @@ gdm_session_worker_get_environment (GdmSessionWorker *
         return (const char * const *) pam_getenvlist (worker->priv->pam_handle);
 }
 
+#ifdef WITH_CONSOLE_KIT
+static void
+register_ck_session (GdmSessionWorker *worker)
+{
+        open_ck_session (worker);
+
+        if (worker->priv->session_cookie != NULL) {
+                gdm_session_worker_set_environment_variable (worker,
+                                                             "XDG_SESSION_COOKIE",
+                                                             worker->priv->session_cookie);
+        }
+}
+#endif
+
 static gboolean
 run_script (GdmSessionWorker *worker,
             const char       *dir)
@@ -1766,6 +2020,10 @@ session_worker_child_watch (GPid              pid,
                  : WIFSIGNALED (status) ? WTERMSIG (status)
                  : -1);
 
+#ifdef WITH_CONSOLE_KIT
+        close_ck_session (worker);
+#endif
+
         gdm_session_worker_uninitialize_pam (worker, PAM_SUCCESS);
 
         worker->priv->child_pid = -1;
@@ -1978,6 +2236,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
 
         error_code = PAM_SUCCESS;
 
+#ifdef WITH_SYSTEMD
         /* If we're in new vt mode, jump to the new vt now. There's no need to jump for
          * the other two modes: in the logind case, the session will activate itself when
          * ready, and in the reuse server case, we're already on the correct VT. */
@@ -1986,6 +2245,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
                         jump_to_vt (worker, worker->priv->session_vt);
                 }
         }
+#endif
 
         if (!worker->priv->is_program_session && !run_script (worker, GDMCONFDIR "/PostLogin")) {
                 g_set_error (error,
@@ -2048,6 +2308,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
                         _exit (EXIT_FAILURE);
                 }
 
+#ifdef WITH_SYSTEMD
                 /* Take control of the tty
                  */
                 if (needs_controlling_terminal) {
@@ -2055,6 +2316,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
                                 g_debug ("GdmSessionWorker: could not take control of tty: %m");
                         }
                 }
+#endif
 
 #ifdef HAVE_LOGINCAP
                 if (setusercontext (NULL, passwd_entry, passwd_entry->pw_uid, LOGIN_SETALL) < 0) {
@@ -2186,6 +2448,7 @@ gdm_session_worker_start_session (GdmSessionWorker  *w
         return TRUE;
 }
 
+#ifdef WITH_SYSTEMD
 static gboolean
 set_up_for_new_vt (GdmSessionWorker *worker)
 {
@@ -2286,6 +2549,7 @@ fail:
         close (fd);
         return FALSE;
 }
+#endif
 
 static gboolean
 set_up_for_current_vt (GdmSessionWorker  *worker,
@@ -2353,12 +2617,14 @@ set_up_for_current_vt (GdmSessionWorker  *worker,
          }
 #endif
 
+#ifdef WITH_SYSTEMD
         if (g_strcmp0 (worker->priv->display_seat_id, "seat0") == 0) {
                 g_debug ("GdmSessionWorker: setting XDG_VTNR to current vt");
                 set_xdg_vtnr_to_current_vt (worker);
         } else {
                 g_debug ("GdmSessionWorker: not setting XDG_VTNR since not seat0");
         }
+#endif
 
         return TRUE;
 out:
@@ -2384,6 +2650,7 @@ gdm_session_worker_open_session (GdmSessionWorker  *wo
                 break;
         case GDM_SESSION_DISPLAY_MODE_NEW_VT:
         case GDM_SESSION_DISPLAY_MODE_LOGIND_MANAGED:
+#ifdef WITH_SYSTEMD
                 if (!set_up_for_new_vt (worker)) {
                         g_set_error (error,
                                      GDM_SESSION_WORKER_ERROR,
@@ -2391,6 +2658,7 @@ gdm_session_worker_open_session (GdmSessionWorker  *wo
                                      "Unable to open VT");
                         return FALSE;
                 }
+#endif
                 break;
         }
 
@@ -2413,8 +2681,16 @@ gdm_session_worker_open_session (GdmSessionWorker  *wo
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
                 g_free (worker->priv->session_id);
                 worker->priv->session_id = session_id;
@@ -2968,6 +3244,7 @@ gdm_session_worker_handle_open (GdmDBusWorker         
         return TRUE;
 }
 
+#ifdef SUPPORTS_PAM_EXTENSIONS
 static char **
 filter_extensions (const char * const *extensions)
 {
@@ -2993,6 +3270,7 @@ filter_extensions (const char * const *extensions)
 
         return filtered_extensions;
 }
+#endif
 
 static gboolean
 gdm_session_worker_handle_initialize (GdmDBusWorker         *object,
@@ -3012,8 +3290,10 @@ gdm_session_worker_handle_initialize (GdmDBusWorker   
         while (g_variant_iter_loop (&iter, "{sv}", &key, &value)) {
                 if (g_strcmp0 (key, "service") == 0) {
                         worker->priv->service = g_variant_dup_string (value, NULL);
+#ifdef SUPPORTS_PAM_EXTENSIONS
                 } else if (g_strcmp0 (key, "extensions") == 0) {
                         worker->priv->extensions = filter_extensions (g_variant_get_strv (value, NULL));
+#endif
                 } else if (g_strcmp0 (key, "username") == 0) {
                         worker->priv->username = g_variant_dup_string (value, NULL);
                 } else if (g_strcmp0 (key, "is-program-session") == 0) {
