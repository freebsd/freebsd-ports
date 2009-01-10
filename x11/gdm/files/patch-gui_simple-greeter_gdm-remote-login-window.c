--- gui/simple-greeter/gdm-remote-login-window.c.orig	2008-03-24 11:27:13.000000000 +0100
+++ gui/simple-greeter/gdm-remote-login-window.c	2008-03-24 11:27:31.000000000 +0100
@@ -25,6 +25,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <sys/signal.h>
 #include <errno.h>
 
 #include <glib.h>
