--- lib/libxview/notify/ndet.h.orig	Tue Jun 29 00:18:12 1993
+++ lib/libxview/notify/ndet.h	Sun Oct 12 19:47:56 2003
@@ -17,6 +17,11 @@
 #ifndef	NDET_DEFINED
 #define	NDET_DEFINED
 
+#include <sys/param.h>
+#if (defined(BSD) && (BSD >= 199103))
+#include <signal.h>
+#endif
+
 /*
 ********************** Detector Loop Notes ****************************
 Here is some notes on the detector loop: 
