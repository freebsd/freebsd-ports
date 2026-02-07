Work around for the https://bugzilla.gnome.org/show_bug.cgi?id=739424 bug

Reduces the time gnome-session will consider application, like gnome-shell,
crashes to be fatal. And drop the user back to the login screen.
This will hopefully allow gnome-shell to restart after triggering the bug
above.

--- gnome-session/gsm-app.c.orig	2015-01-01 17:20:24.798482241 +0100
+++ gnome-session/gsm-app.c	2015-01-01 17:20:38.627540889 +0100
@@ -30,7 +30,7 @@
 #define GSM_APP_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GSM_TYPE_APP, GsmAppPrivate))
 
 /* If a component crashes twice within a minute, we count that as a fatal error */
-#define _GSM_APP_RESPAWN_RATELIMIT_SECONDS 60
+#define _GSM_APP_RESPAWN_RATELIMIT_SECONDS 3
 
 struct _GsmAppPrivate
 {
