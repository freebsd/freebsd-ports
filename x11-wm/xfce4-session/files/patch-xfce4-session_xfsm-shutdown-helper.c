--- xfce4-session/xfsm-shutdown.c.orig	2012-04-28 22:43:27.000000000 +0200
+++ xfce4-session/xfsm-shutdown.c	2012-05-17 20:32:41.000000000 +0200
@@ -52,6 +52,9 @@
 #include <signal.h>
 #endif
 
+#include <sys/param.h>
+#include <sys/user.h>
+#include <sys/sysctl.h>
 
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
