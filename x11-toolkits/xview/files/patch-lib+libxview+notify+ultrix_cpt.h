--- lib/libxview/notify/ultrix_cpt.h.orig	Fri Oct 17 00:27:24 2003
+++ lib/libxview/notify/ultrix_cpt.h	Fri Oct 17 00:43:03 2003
@@ -14,7 +14,10 @@
 #ifndef xview_ultrix_compat_DEFINED
 #define xview_ultrix_compat_DEFINED
 
-#ifdef OLD_BSD_FDSETS
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/select.h>
+#elif defined(OLD_BSD_FDSETS)
 
 #ifndef NBBY
 #define NBBY    8               /* number of bits in a byte */
