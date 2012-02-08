--- lib/libxview/textsw/es_file.c.orig	2005-03-28 06:40:33.000000000 -0800
+++ lib/libxview/textsw/es_file.c	2012-02-03 09:41:57.345780320 -0800
@@ -85,14 +85,14 @@
 
 #include <string.h>
 #include <fcntl.h>
-#if defined SVR4 || defined __CYGWIN__
+#include <sys/param.h>
+#if defined SVR4 || defined __CYGWIN__ || defined(BSD4_4)
 #include <stdlib.h>
 #include <dirent.h>
 #else
 #include <sys/dir.h>
 #endif /* SVR4 */
 #include <sys/errno.h>
-#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/file.h>
@@ -115,11 +115,16 @@
 #if (defined(__linux__) && defined(__GLIBC__)) || defined(__CYGWIN__)
 /* martin.buck@bigfoot.com */
 #include <errno.h>
+#elif defined(__FreeBSD__)
+extern int    errno;
+extern const  sys_nerr;
+extern const char *const sys_err_list[];
+extern off_t  lseek();
 #else
 extern int      errno, sys_nerr;
 extern char    *sys_errlist[];
 #endif
-#ifndef __CYGWIN__
+#if !defined(__CYGWIN__) && !defined(__FreeBSD__)
 extern long     lseek();
 #endif
 
