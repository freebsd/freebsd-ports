--- src/gdm-queue.c.orig	Fri Feb  2 23:52:26 2007
+++ src/gdm-queue.c	Fri Feb  2 23:52:32 2007
@@ -32,6 +32,7 @@
 #include <sys/un.h>
 #include <errno.h>
 #include <stdio.h>
+#include <signal.h>
 
 #include "gdm-queue.h"
 
