--- ksysguard/ksysguardd/FreeBSD/apm.c.orig	Sat May  4 16:53:10 2002
+++ ksysguard/ksysguardd/FreeBSD/apm.c	Sat May  4 16:53:42 2002
@@ -18,7 +18,7 @@
 
 	$Id: apm.c,v 1.2 2001/09/18 14:03:53 tokoe Exp $
 */
-
+#ifdef __i386__
 #include <fcntl.h>
 #include <machine/apm_bios.h>
 #include <stdio.h>
@@ -96,3 +96,4 @@
 {
 	fprintf(CurrentClient, "Remaining battery time\t0\t0\tmin\n");
 }
+#endif /* __i386__ */
