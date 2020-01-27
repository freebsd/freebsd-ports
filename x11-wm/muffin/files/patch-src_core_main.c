--- src/core/main.c.orig	2015-02-02 16:02:44 UTC
+++ src/core/main.c
@@ -61,7 +61,11 @@
 
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
