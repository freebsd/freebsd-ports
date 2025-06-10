--- gnome-flashback/libscreensaver/gf-screensaver.c.orig	2021-11-02 10:13:49 UTC
+++ gnome-flashback/libscreensaver/gf-screensaver.c
@@ -30,7 +30,7 @@
 #include "gf-prefs.h"
 #include "gf-watcher.h"
 
-#define PAM_CONFIG_FILE "/etc/pam.d/gnome-flashback"
+#define PAM_CONFIG_FILE "%%PREFIX%%/etc/pam.d/gnome-flashback"
 
 struct _GfScreensaver
 {
