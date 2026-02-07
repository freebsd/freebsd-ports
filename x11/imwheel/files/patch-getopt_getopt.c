--- getopt/getopt.c.orig	2016-06-20 12:59:05 UTC
+++ getopt/getopt.c
@@ -166,11 +166,12 @@ static enum
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
