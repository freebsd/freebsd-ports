--- src/core/main.c.orig	2009-08-25 13:49:41.000000000 -0400
+++ src/core/main.c	2009-12-19 15:03:26.000000000 -0500
@@ -59,7 +59,11 @@
 
 #include <stdlib.h>
 #include <sys/types.h>
+#ifdef __linux__
 #include <wait.h>
+#else
+#include <sys/wait.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <signal.h>
@@ -445,6 +449,9 @@ sigterm_handler (int signum)
 }
 
 static guint sigchld_signal_id = 0;
+#ifndef CLD_EXITED
+#define CLD_EXITED 1
+#endif
 
 static void
 sigchld_handler (int signum, siginfo_t *info, void *context)
