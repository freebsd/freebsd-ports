--- plugins/launcher/launcher-exec.c.orig	2009-01-15 13:10:55.000000000 +0100
+++ plugins/launcher/launcher-exec.c	2009-01-15 13:11:12.000000000 +0100
@@ -49,6 +49,10 @@
 #define WAIT_ANY (-1)
 #endif
 
+#ifndef environ
+extern char **environ;
+#endif
+
 #include "launcher.h"
 #include "launcher-exec.h"
 
