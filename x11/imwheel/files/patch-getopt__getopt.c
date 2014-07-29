--- getopt/getopt.c.orig	Tue Apr  6 05:22:57 1999
+++ getopt/getopt.c	Fri Jun 29 01:22:22 2001
@@ -166,11 +166,12 @@
 /* Value of POSIXLY_CORRECT environment variable.  */
 static char *posixly_correct;
 
-#ifdef	__GNU_LIBRARY__
+#if defined(__GNU_LIBRARY__) || defined(__FreeBSD__)
 /* We want to avoid inclusion of string.h with non-GNU libraries
    because there are many ways it can cause trouble.
    On some systems, it contains special magic macros that don't work
    in GCC.  */
+#include <stdlib.h>
 #include <string.h>
 #define	my_index	strchr
 #else
