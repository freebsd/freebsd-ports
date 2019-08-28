--- src/modules/sysinfo/cpuclock/cpuclock_sysctl.c.orig	2019-07-23 16:46:44 UTC
+++ src/modules/sysinfo/cpuclock/cpuclock_sysctl.c
@@ -2,6 +2,7 @@
 #include <stdlib.h>
 
 #if defined(__FreeBSD__) || defined(__DragonFly__)
+# include <sys/types.h>
 # include <sys/sysctl.h>
 #endif
 
