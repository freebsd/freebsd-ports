--- lib/libxview/notify/ndet_auto.c.orig	Sun Oct 12 19:37:15 2003
+++ lib/libxview/notify/ndet_auto.c	Sun Oct 12 19:39:34 2003
@@ -21,7 +21,8 @@
 #include <xview_private/ndis.h>	/* For ndis_enqueue */
 #include <errno.h>
 #include <signal.h>
-#ifdef SVR4 
+#include <sys/param.h>
+#if defined(SVR4) || defined(BSD4_4) 
 #include <stdlib.h> 
 #endif SVR4
 
