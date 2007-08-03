--- clients/olwm/slave.c.orig	1993-06-29 07:11:57.000000000 +0200
+++ clients/olwm/slave.c	2007-08-03 15:01:51.000000000 +0200
@@ -22,6 +22,8 @@
 #include <signal.h>
 #include <stdio.h>
 
+#include <sys/param.h>
+
 #include "cmdstream.h"
 #include "error.h"
 
@@ -44,7 +46,7 @@
  *	Local Forward Declarations
  * ---------------------------------------------------------------------*/
 
-void	SlaveFailure();
+static void	SlaveFailure();
 
 
 /* ----------------------------------------------------------------------
