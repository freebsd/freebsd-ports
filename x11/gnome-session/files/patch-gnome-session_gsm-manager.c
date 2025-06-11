--- gnome-session/gsm-manager.c.orig	2024-09-19 12:36:55 UTC
+++ gnome-session/gsm-manager.c
@@ -40,9 +40,17 @@
 #include "gsm-manager.h"
 #include "org.gnome.SessionManager.h"
 
+#ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
+#endif
 
+#ifdef HAVE_SYSTEMD
 #include <systemd/sd-daemon.h>
+#else
+/* So we don't need to add ifdef's everywhere */
+#define sd_notify(u, m)            do {} while (0)
+#define sd_notifyf(u, m, ...)      do {} while (0)
+#endif
 
 #include "gsm-store.h"
 #include "gsm-inhibitor.h"
@@ -280,10 +288,12 @@ on_required_app_failure (GsmManager  *manager,
                 allow_logout = !_log_out_is_locked_down (manager);
         }
 
+#ifdef ENABLE_SYSTEMD_JOURNAL
         sd_journal_send ("MESSAGE_ID=%s", GSM_MANAGER_UNRECOVERABLE_FAILURE_MSGID,
                          "PRIORITY=%d", 3,
                          "MESSAGE=Unrecoverable failure in required component %s", app_id,
                          NULL);
+#endif
 
         gsm_fail_whale_dialog_we_failed (FALSE,
                                          allow_logout,
@@ -308,10 +318,12 @@ on_display_server_failure (GsmManager *manager,
                 extensions = NULL;
         }
 
+#ifdef ENABLE_SYSTEMD_JOURNAL
         sd_journal_send ("MESSAGE_ID=%s", GSM_MANAGER_UNRECOVERABLE_FAILURE_MSGID,
                          "PRIORITY=%d", 3,
                          "MESSAGE=Unrecoverable failure in required component %s", app_id,
                          NULL);
+#endif
 
         gsm_quit ();
 }
@@ -966,6 +978,7 @@ _client_stop (const char *id,
         return FALSE;
 }
 
+#ifdef HAVE_SYSTEMD
 static void
 maybe_restart_user_bus (GsmManager *manager)
 {
@@ -998,6 +1011,7 @@ maybe_restart_user_bus (GsmManager *manager)
                 g_debug ("GsmManager: reloading user bus failed: %s", error->message);
         }
 }
+#endif
 
 static void
 do_phase_exit (GsmManager *manager)
@@ -1010,8 +1024,10 @@ do_phase_exit (GsmManager *manager)
                                    NULL);
         }
 
+#ifdef HAVE_SYSTEMD
         if (!priv->systemd_managed)
                 maybe_restart_user_bus (manager);
+#endif
 
         end_phase (manager);
 }
@@ -1405,10 +1421,12 @@ start_phase (GsmManager *manager)
                 do_phase_startup (manager);
                 break;
         case GSM_MANAGER_PHASE_RUNNING:
+#ifdef ENABLE_SYSTEMD_JOURNAL
                 sd_journal_send ("MESSAGE_ID=%s", GSM_MANAGER_STARTUP_SUCCEEDED_MSGID,
                                  "PRIORITY=%d", 5,
                                  "MESSAGE=Entering running state",
                                  NULL);
+#endif
 #ifdef HAVE_X11
                 gsm_xsmp_server_start_accepting_new_clients (priv->xsmp_server);
 #endif
