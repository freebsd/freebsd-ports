--- gnome-flashback/libscreensaver/gf-screensaver-utils.c.orig	2023-08-12 06:50:17 UTC
+++ gnome-flashback/libscreensaver/gf-screensaver-utils.c
@@ -18,7 +18,8 @@
 #include "config.h"
 #include "gf-screensaver-utils.h"
 
-#include <systemd/sd-login.h>
+#include <gio/gio.h>
+#include <sd-login.h>
 #include <unistd.h>
 
 gboolean
