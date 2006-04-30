--- daemon/server.c.orig	Thu Jan  5 16:58:37 2006
+++ daemon/server.c	Thu Jan  5 16:58:46 2006
@@ -29,6 +29,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
+#include <sys/resource.h>
 #include <strings.h>
 #include <signal.h>
 #include <syslog.h>
