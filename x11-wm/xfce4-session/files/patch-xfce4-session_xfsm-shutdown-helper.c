--- xfce4-session/xfsm-shutdown-helper.c.orig	2010-11-03 21:11:37.000000000 +0100
+++ xfce4-session/xfsm-shutdown-helper.c	2010-11-16 17:15:07.000000000 +0100
@@ -58,6 +58,9 @@
 #include <errno.h>
 #endif
 
+#include <sys/param.h>
+#include <sys/user.h>
+#include <sys/sysctl.h>
 #include <dbus/dbus.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
