--- src/notification.c.orig	2011-08-11 11:03:46.000000000 +0200
+++ src/notification.c	2011-08-11 11:05:21.000000000 +0200
@@ -184,10 +184,10 @@
             icon = freeme = g_filename_to_uri (icon_file, NULL, NULL);
           }
 
-          notif = notify_notification_new_with_status_icon (
+          notif = notify_notification_new (
                               message[0] /* title */,
                               message[1] /* summary */,
-                              icon, status_icon);
+                              icon);
 
           g_strfreev (message);
           g_free (freeme);
