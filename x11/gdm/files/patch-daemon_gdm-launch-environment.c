$OpenBSD: patch-daemon_gdm-launch-environment_c,v 1.8 2017/04/17 13:17:07 ajacoutot Exp $

XXX fix+push upstream

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 1ac67f522f5690c27023d98096ca817f12f7eb88 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:28:01 -0400
Subject: drop consolekit support

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From a9cacb929470eb82582396984c61d5b611bfeb1a Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 14:33:40 -0400
Subject: session: drop session-type property

--- daemon/gdm-launch-environment.c.orig	Wed Apr 12 15:47:09 2017
+++ daemon/gdm-launch-environment.c	Mon Apr 17 14:17:28 2017
@@ -197,6 +197,9 @@ build_launch_environment (GdmLaunchEnvironment *launch
                 char *seat_id;
 
                 seat_id = launch_environment->priv->x11_display_seat_id;
+                if (g_str_has_prefix (seat_id, "/org/freedesktop/ConsoleKit/")) {
+                        seat_id += strlen ("/org/freedesktop/ConsoleKit/");
+                }
 
                 g_hash_table_insert (hash, g_strdup ("GDM_SEAT_ID"), g_strdup (seat_id));
         }
@@ -224,6 +227,8 @@ on_session_setup_complete (GdmSession        *session,
                 gdm_session_set_environment_variable (launch_environment->priv->session, key, value);
         }
         g_hash_table_destroy (hash);
+
+        gdm_session_select_session_type (launch_environment->priv->session, "LoginWindow");
 }
 
 static void
