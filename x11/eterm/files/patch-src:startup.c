--- src/startup.c.orig	Mon Feb  7 22:24:54 2000
+++ src/startup.c	Mon Feb  7 22:24:57 2000
@@ -29,6 +29,8 @@
 #include "config.h"
 #include "feature.h"
 
+#define NEED_LINUX_HACK 1
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
