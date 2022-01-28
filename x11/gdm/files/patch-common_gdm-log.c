--- common/gdm-log.c.orig	2022-01-12 14:15:56 UTC
+++ common/gdm-log.c
@@ -30,7 +30,9 @@
 #include <unistd.h>
 
 #include <syslog.h>
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #include <glib.h>
 #include <glib/gstdio.h>
@@ -131,6 +133,20 @@ gdm_log_init (void)
         initialized = TRUE;
 
         g_log_set_default_handler (gdm_log_default_handler, NULL);
+
+#ifndef WITH_SYSTEMD
+        /* Only set up syslog if !systemd, otherwise with systemd
+         * enabled, we keep the default GLib log handler which goes to
+         * stderr, which is routed to the appropriate place in the
+         * systemd service file.
+         */
+        const char *prg_name = g_get_prgname ();
+        int options = LOG_PID;
+#ifdef LOG_PERROR
+        options |= LOG_PERROR;
+#endif
+        openlog (prg_name, options, LOG_DAEMON);
+#endif
 }
 
 void
