--- daemon/errorgui.c.orig	Tue Sep 23 00:39:10 2003
+++ daemon/errorgui.c	Tue Sep 23 00:39:21 2003
@@ -32,6 +32,7 @@
 #include <sys/stat.h>
 #include <pwd.h>
 #include <sys/types.h>
+#include <signal.h>
 #include "gdm.h"
 #include "misc.h"
 #include "auth.h"
