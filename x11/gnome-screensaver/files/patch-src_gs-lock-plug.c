--- src/gs-lock-plug.c.orig	2011-03-06 21:27:00.000000000 +0100
+++ src/gs-lock-plug.c	2011-03-06 21:27:36.000000000 +0100
@@ -1090,7 +1090,7 @@ submit_note (GtkButton  *button,
         strftime (summary, 128, "%X", tmp);
 
         notify_init ("gnome-screensaver-dialog");
-        note = notify_notification_new (summary, escaped_text, NULL, NULL);
+        note = notify_notification_new (summary, escaped_text, NULL);
         notify_notification_set_timeout (note, NOTIFY_EXPIRES_NEVER);
         notify_notification_show (note, NULL);
         g_object_unref (note);
