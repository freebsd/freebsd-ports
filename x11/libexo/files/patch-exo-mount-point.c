--- exo/exo-mount-point.c.orig	2010-01-14 17:36:19.000000000 +0100
+++ exo/exo-mount-point.c	2010-01-14 17:36:41.000000000 +0100
@@ -38,6 +38,9 @@
 #include <sys/ucred.h>
 #endif
 #ifdef HAVE_SYS_MOUNT_H
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #include <sys/mount.h>
 #endif
 
