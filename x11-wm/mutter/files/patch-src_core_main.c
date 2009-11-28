--- src/core/main.c.orig	2009-08-14 00:40:56.000000000 +0000
+++ src/core/main.c	2009-08-14 00:41:22.000000000 +0000
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
