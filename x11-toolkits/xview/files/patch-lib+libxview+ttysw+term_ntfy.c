--- lib/libxview/ttysw/term_ntfy.c.orig	Fri Oct 17 10:07:41 2003
+++ lib/libxview/ttysw/term_ntfy.c	Fri Oct 17 10:07:41 2003
@@ -22,7 +22,8 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
-#ifdef SVR4
+#include <sys/param.h>
+#if (defined(BSD4_4) || defined(SVR4))
 #include <unistd.h>
 #endif
 
@@ -63,7 +64,7 @@
 /* performance: global cache of getdtablesize() */
 extern int      dtablesize_cache;
 
-#ifdef SVR4
+#if (defined(BSD4_4) || defined(SVR4))
 #define GETDTABLESIZE() \
 (dtablesize_cache?dtablesize_cache:(dtablesize_cache=(int)sysconf(_SC_OPEN_MAX)))
 #else
