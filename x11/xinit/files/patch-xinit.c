--- xinit.c.orig	2011-04-26 07:03:42.000000000 +0200
+++ xinit.c	2011-08-06 22:14:03.000000000 +0200
@@ -49,10 +49,10 @@
 #endif
 
 /* For PRIO_PROCESS and setpriority() */
-#ifdef __DragonFly__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 #include <sys/time.h>
 #include <sys/resource.h>
-#endif /* __DragonFly__ */
+#endif
 
 #include <stdlib.h>
 
