Work around for the https://bugzilla.gnome.org/show_bug.cgi?id=739424 bug

Reduces the time gnome-session will consider application, like gnome-shell,
crashes to be fatal. And drop the user back to the login screen.
This will hopefully allow gnome-shell to restart after triggering the bug
above.

--- gnome-session/gsm-app.c.orig	2024-01-04 21:31:40 UTC
+++ gnome-session/gsm-app.c
@@ -28,7 +28,7 @@
 #include "org.gnome.SessionManager.App.h"
 
 /* If a component crashes twice within a minute, we count that as a fatal error */
-#define _GSM_APP_RESPAWN_RATELIMIT_SECONDS 60
+#define _GSM_APP_RESPAWN_RATELIMIT_SECONDS 3
 
 typedef struct
 {
