--- src/gdm-queue.c.orig	Thu Nov 16 12:39:45 2006
+++ src/gdm-queue.c	Thu Nov 16 12:40:17 2006
@@ -31,6 +31,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <errno.h>
+#include <signal.h>
 #include <stdio.h>
 
 #include "gdm-queue.h"
