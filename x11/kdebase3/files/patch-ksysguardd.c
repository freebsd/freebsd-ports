--- ksysguard/ksysguardd/FreeBSD/ksysguardd.c.orig	Sat Nov 10 00:17:04 2001
+++ ksysguard/ksysguardd/FreeBSD/ksysguardd.c	Sun Dec  9 22:26:48 2001
@@ -37,6 +37,8 @@
 #include <sys/wait.h>
 #include <unistd.h>
 
+#include "config.h"
+
 #include "CPU.h"
 #include "Command.h"
 #include "Memory.h"
