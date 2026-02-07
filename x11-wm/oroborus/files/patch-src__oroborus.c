--- src/oroborus.c.orig	2006-01-12 15:40:43 UTC
+++ src/oroborus.c
@@ -33,6 +33,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include "client.h"
 #include "events.h"
