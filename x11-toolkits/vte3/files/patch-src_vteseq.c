--- src/vteseq.c.orig	Mon Jun 12 20:27:00 2006
+++ src/vteseq.c	Mon Jun 12 20:27:19 2006
@@ -20,6 +20,7 @@
 #include "../config.h"
 
 #ifdef HAVE_SYS_SYSLIMITS_H
+#include <sys/cdefs.h>
 #include <sys/syslimits.h>
 #endif
 
