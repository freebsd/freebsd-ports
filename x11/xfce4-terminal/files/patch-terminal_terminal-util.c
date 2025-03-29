--- terminal/terminal-util.c.orig	2025-03-26 18:40:26 UTC
+++ terminal/terminal-util.c
@@ -30,13 +30,13 @@
 #endif
 
 #ifdef __FreeBSD__
-#include <libprocstat.h>
-#include <libutil.h>
 #include <sys/param.h>
 #include <sys/queue.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/user.h>
+#include <libprocstat.h>
+#include <libutil.h>
 #endif
 
 #ifdef ENABLE_X11
