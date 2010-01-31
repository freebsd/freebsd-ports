--- src/core/delete.c.orig	2010-01-30 18:56:27.000000000 -0500
+++ src/core/delete.c	2010-01-30 18:56:53.000000000 -0500
@@ -32,6 +32,7 @@
 #include "workspace.h"
 
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <signal.h>
 #include <unistd.h>
 #include <errno.h>
