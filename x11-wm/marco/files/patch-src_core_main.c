--- src/core/main.c.orig	2010-01-21 11:09:25.000000000 -0500
+++ src/core/main.c	2010-01-30 18:53:17.000000000 -0500
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
