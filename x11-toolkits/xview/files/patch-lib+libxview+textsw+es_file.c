--- lib/libxview/textsw/es_file.c.orig	Tue Jun 29 00:17:34 1993
+++ lib/libxview/textsw/es_file.c	Sat Oct  4 18:46:45 2003
@@ -85,14 +85,14 @@
 
 #include <string.h>
 #include <fcntl.h>
-#ifdef SVR4
+#include <sys/param.h>
+#if (defined(BSD4_4) || defined(SVR4))
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
@@ -109,9 +109,15 @@
 #include <xview_private/txt_18impl.h>
 
 
-extern int      errno, sys_nerr;
+extern int	errno;
+extern const	sys_nerr;
+#if (defined(BSD) && (BSD >= 199306))
+extern const char *const sys_err_list[];
+extern off_t	lseek();
+#else
 extern char    *sys_errlist[];
 extern long     lseek();
+#endif
 
 static void update_read_buf();  /* update the read buf if overlaps write buf */
 static Es_status es_file_commit();
