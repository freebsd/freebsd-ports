--- src/dumpkeys.c.orig	Wed Dec  4 02:04:12 2002
+++ src/dumpkeys.c	Wed Dec  4 02:04:30 2002
@@ -18,11 +18,11 @@
 
 #ident "$Id: patch-src_dumpkeys.c,v 1.1 2002/12/04 07:10:42 marcus Exp $"
 #include "../config.h"
+#include <sys/types.h>
 #ifdef HAVE_SYS_SELECT_H
 #include <sys/select.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <signal.h>
