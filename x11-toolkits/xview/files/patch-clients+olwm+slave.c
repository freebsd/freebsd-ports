--- ./clients/olwm/slave.c.orig	Tue Jun 29 07:11:57 1993
+++ ./clients/olwm/slave.c	Sat Apr  1 18:26:06 2000
@@ -22,6 +22,8 @@
 #include <signal.h>
 #include <stdio.h>
 
+#include <sys/param.h>
+
 #include "cmdstream.h"
 #include "error.h"
 
