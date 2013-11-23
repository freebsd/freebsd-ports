--- mate-session/gsm-autostart-app.c.orig	2008-08-20 14:18:52.000000000 -0400
+++ mate-session/gsm-autostart-app.c	2008-08-20 14:19:02.000000000 -0400
@@ -25,6 +25,7 @@
 #include <string.h>
 #include <sys/wait.h>
 #include <errno.h>
+#include <signal.h>
 
 #include <glib.h>
 #include <gio/gio.h>
