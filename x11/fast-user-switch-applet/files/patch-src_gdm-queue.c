--- src/gdm-queue.c.orig	2008-02-09 11:06:43.000000000 -0500
+++ src/gdm-queue.c	2008-02-09 11:06:53.000000000 -0500
@@ -32,6 +32,7 @@
 #include <sys/un.h>
 #include <errno.h>
 #include <stdio.h>
+#include <signal.h>
 
 #include "gdm-queue.h"
 
