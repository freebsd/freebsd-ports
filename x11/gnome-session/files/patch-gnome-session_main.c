--- gnome-session/main.c.orig	2024-03-18 19:30:06 UTC
+++ gnome-session/main.c
@@ -43,11 +43,14 @@
 #include "gsm-system.h"
 #include "gsm-fail-whale.h"
 
+#ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
+#endif
 
 #define GSM_DBUS_NAME "org.gnome.SessionManager"
 
 static gboolean systemd_service = FALSE;
+static gboolean use_systemd = USE_SYSTEMD_SESSION;
 static gboolean failsafe = FALSE;
 static gboolean show_version = FALSE;
 static gboolean debug = FALSE;
@@ -280,6 +283,7 @@ initialize_gio (void)
         }
 }
 
+#ifdef ENABLE_SYSTEMD_SESSION
 static gboolean
 leader_term_or_int_signal_cb (gpointer data)
 {
@@ -485,6 +489,7 @@ systemd_leader_run(void)
         gsm_main ();
         exit(0);
 }
+#endif /* ENABLE_SYSTEMD_SESSION */
 
 int
 main (int argc, char **argv)
@@ -499,7 +504,11 @@ main (int argc, char **argv)
         guint             name_owner_id;
         GOptionContext   *options;
         static GOptionEntry entries[] = {
+#ifdef ENABLE_SYSTEMD_SESSION
                 { "systemd-service", 0, 0, G_OPTION_ARG_NONE, &systemd_service, N_("Running as systemd service"), NULL },
+                { "systemd", 0, 0, G_OPTION_ARG_NONE, &use_systemd, N_("Use systemd session management"), NULL },
+#endif
+                { "builtin", 0, G_OPTION_FLAG_REVERSE, G_OPTION_ARG_NONE, &use_systemd, N_("Use builtin session management (rather than the systemd based one)"), NULL },
                 { "autostart", 'a', 0, G_OPTION_ARG_STRING_ARRAY, &override_autostart_dirs, N_("Override standard autostart directories"), N_("AUTOSTART_DIR") },
                 { "session", 0, 0, G_OPTION_ARG_STRING, &opt_session_name, N_("Session to use"), N_("SESSION_NAME") },
                 { "debug", 0, 0, G_OPTION_ARG_NONE, &debug, N_("Enable debugging code"), NULL },
@@ -553,6 +562,7 @@ main (int argc, char **argv)
          * journald picks ups the nicer "gnome-session" as the program
          * name instead of whatever shell script GDM happened to use.
          */
+#ifdef ENABLE_SYSTEMD_JOURNAL
         if (!debug) {
                 int journalfd;
 
@@ -562,6 +572,7 @@ main (int argc, char **argv)
                         dup2(journalfd, 2);
                 }
         }
+#endif
 
         gdm_log_init ();
         gdm_log_set_debug (debug);
@@ -636,12 +647,15 @@ main (int argc, char **argv)
 
         session_name = opt_session_name;
 
+#ifdef HAVE_SYSTEMD
         gsm_util_export_user_environment (&error);
         if (error && !g_getenv ("RUNNING_UNDER_GDM"))
                 g_warning ("Failed to upload environment to systemd: %s", error->message);
         g_clear_error (&error);
+#endif
 
-        if (!systemd_service) {
+#ifdef ENABLE_SYSTEMD_SESSION
+        if (use_systemd && !systemd_service) {
                 const gchar *session_type = NULL;
                 g_autofree gchar *gnome_session_target = NULL;
 
@@ -688,6 +702,7 @@ main (int argc, char **argv)
                         exit (1);
                 }
         }
+#endif /* ENABLE_SYSTEMD_SESSION */
 
         {
                 gchar *ibus_path;
@@ -724,7 +739,9 @@ main (int argc, char **argv)
 
         gsm_main ();
 
+#ifdef HAVE_SYSTEMD
         gsm_util_export_user_environment (NULL);
+#endif
 
         g_clear_object (&manager);
         g_free (gl_renderer);
