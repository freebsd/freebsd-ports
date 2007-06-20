--- src/oroborus.c.orig	Fri Jan 13 00:40:43 2006
+++ src/oroborus.c	Thu Apr 26 02:11:54 2007
@@ -33,6 +33,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include "client.h"
 #include "events.h"
