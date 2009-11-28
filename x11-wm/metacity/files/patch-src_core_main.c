--- src/core/main.c.orig	2009-09-08 16:55:35.000000000 -0400
+++ src/core/main.c	2009-10-02 23:36:53.000000000 -0400
@@ -58,7 +58,11 @@
 
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
@@ -378,6 +382,9 @@ sigterm_handler (int signum)
 }
 
 static guint sigchld_signal_id = 0;
+#ifndef CLD_EXITED
+#define CLD_EXITED 1
+#endif
 
 static void
 sigchld_handler (int signum, siginfo_t *info, void *context)
