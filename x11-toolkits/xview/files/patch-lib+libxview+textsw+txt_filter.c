--- lib/libxview/textsw/txt_filter.c.orig	Sun Oct  5 14:57:49 2003
+++ lib/libxview/textsw/txt_filter.c	Sun Oct  5 15:20:32 2003
@@ -17,7 +17,8 @@
 #include "types.h"
 #include <sys/file.h>
 #include <unistd.h>
-#ifdef SVR4
+#include <sys/param.h>
+#if (defined(BSD4_4) || defined(SVR4))
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -32,7 +33,7 @@
 #include <string.h>
 
 #ifdef sparc
-#ifdef SVR4
+#if (defined(BSD4_4) || defined(SVR4))
 #include <unistd.h>
 #else
 #include <vfork.h>
@@ -54,6 +57,9 @@
 #define	REPLY_ERROR	-1
 #define	REPLY_OKAY	 0
 #define	REPLY_SEND	 1
+
+static int	talk_to_filter();
+static int	start_filter();
 
 /* performance: global cache of getdtablesize() */
 extern int      dtablesize_cache;
