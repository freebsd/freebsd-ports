--- gnome-session/gsm-autostart-app.c.orig	2024-03-18 19:30:06 UTC
+++ gnome-session/gsm-autostart-app.c
@@ -31,8 +31,12 @@
 #define GNOME_DESKTOP_USE_UNSTABLE_API
 #include <libgnome-desktop/gnome-systemd.h>
 
+#ifdef HAVE_SYSTEMD
+#ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
+#endif
 #include <systemd/sd-daemon.h>
+#endif
 
 #include "gsm-autostart-app.h"
 #include "gsm-util.h"
@@ -957,6 +961,7 @@ app_launched (GAppLaunchContext *ctx,
                                    NULL, NULL, NULL);
 }
 
+#ifdef ENABLE_SYSTEMD_JOURNAL
 static void
 on_child_setup (GsmAutostartApp *app)
 {
@@ -983,6 +988,7 @@ on_child_setup (GsmAutostartApp *app)
                 close (standard_error);
         }
 }
+#endif
 
 static gboolean
 autostart_app_start_spawn (GsmAutostartApp *app,
@@ -1033,10 +1039,12 @@ autostart_app_start_spawn (GsmAutostartApp *app,
                 g_app_launch_context_setenv (ctx, "DESKTOP_AUTOSTART_ID", startup_id);
         }
 
+#ifdef ENABLE_SYSTEMD_JOURNAL
         if (sd_booted () > 0) {
                 child_setup_func = (GSpawnChildSetupFunc) on_child_setup;
                 child_setup_data = app;
         }
+#endif
 
         handler = g_signal_connect (ctx, "launched", G_CALLBACK (app_launched), app);
         success = g_desktop_app_info_launch_uris_as_manager (priv->app_info,
