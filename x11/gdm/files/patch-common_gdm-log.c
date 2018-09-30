$OpenBSD: patch-common_gdm-log_c,v 1.1 2015/10/18 13:25:54 ajacoutot Exp $

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 9be58c9ec9a3a411492a5182ac4b0d51fdc3a323 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:48:52 -0400
Subject: require logind support

--- common/gdm-log.c.orig	2018-02-19 19:16:32.000000000 +0100
+++ common/gdm-log.c	2018-04-05 21:59:25.290775000 +0200
@@ -30,7 +30,9 @@
 #include <unistd.h>
 
 #include <syslog.h>
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #include <glib.h>
 #include <glib/gstdio.h>
@@ -125,12 +127,35 @@ gdm_log_set_debug (gboolean debug)
 void
 gdm_log_init (void)
 {
+        const char *prg_name;
+        int         options;
+ 
         if (initialized)
                 return;
 
         initialized = TRUE;
 
+#ifdef WITH_SYSTEMD
+        is_sd_booted = sd_booted () > 0;
+#endif
+
         g_log_set_default_handler (gdm_log_default_handler, NULL);
+
+        /* Only set up syslog if !systemd, otherwise with systemd
+         * enabled, we keep the default GLib log handler which goes to
+         * stderr, which is routed to the appropriate place in the
+         * systemd service file.
+         */
+        if (!is_sd_booted) {
+                prg_name = g_get_prgname ();
+
+                options = LOG_PID;
+#ifdef LOG_PERROR
+                options |= LOG_PERROR;
+#endif
+
+                openlog (prg_name, options, LOG_DAEMON);
+        }
 }
 
 void
