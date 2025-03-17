--- src/ptyxis-tab.c.orig	2025-03-15 16:56:42 UTC
+++ src/ptyxis-tab.c
@@ -22,11 +22,9 @@
 #include "config.h"
 
 #include <glib/gi18n.h>
-
-#ifdef __linux__
+#include <sys/wait.h>
 # include <libportal/portal.h>
 # include <libportal-gtk4/portal-gtk4.h>
-#endif
 
 #include "ptyxis-agent-ipc.h"
 #include "ptyxis-application.h"
