--- src/task-manager-freebsd.c.orig	2010-05-21 06:29:33.000000000 -0700
+++ src/task-manager-freebsd.c	2011-10-27 12:42:24.425260800 -0700
@@ -18,6 +18,9 @@
 #include <fcntl.h>
 #include <paths.h>
 #include <unistd.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900030
+#include <sys/vmmeter.h>
+#endif
 
 #include <glib.h>
 
