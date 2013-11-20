--- src/core/main.c.orig	2010-02-12 12:17:38.000000000 -0500
+++ src/core/main.c	2010-02-19 01:22:45.000000000 -0500
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
