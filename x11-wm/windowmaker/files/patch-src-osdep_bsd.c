--- src/osdep_bsd.c.orig	2014-03-09 06:12:39.000000000 +0900
+++ src/osdep_bsd.c	2014-03-09 06:14:45.000000000 +0900
@@ -85,8 +85,6 @@
 	if (argmax == 0) { /* it hopefully doesn't change at runtime *g* */
 		mib[0] = CTL_KERN;
 		mib[1] = KERN_ARGMAX;
-		mib[2] = 0;
-		mib[4] = 0;
 
 		count = sizeof(argmax);
 		if (sysctl(mib, 2, &argmax, &count, NULL, 0) == -1)
