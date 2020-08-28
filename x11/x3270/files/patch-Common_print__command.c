--- Common/print_command.c.orig	2020-08-27 23:10:43 UTC
+++ Common/print_command.c
@@ -34,6 +34,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <assert.h>
+#include <sys/wait.h>
 
 #include "popups.h"
 #include "print_command.h"
