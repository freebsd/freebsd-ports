--- lib/libxview/textsw/txt_file.c.orig	2005-03-28 06:40:33.000000000 -0800
+++ lib/libxview/textsw/txt_file.c	2012-02-03 10:12:40.144095469 -0800
@@ -18,10 +18,13 @@
 #include <xview_private/txt_impl.h>
 #include <xview_private/ev_impl.h>
 #include <xview_private/txt_18impl.h>
-#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__)
+#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)
 #include <dirent.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/file.h>
+#endif
 #if defined(__linux__) || defined(__CYGWIN__)
 #include <sys/types.h>
 #include <fcntl.h>
@@ -37,7 +40,6 @@
  */
 #undef MIN
 #undef MAX
-#include <sys/param.h>
 #include <xview/notice.h>
 #include <xview/frame.h>
 #include <errno.h>
@@ -47,7 +49,7 @@
 	if ((unsigned)(to_test) != 0) (flags) |= (flag);	\
 	else (flags) &= ~(flag)
 
-#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__)
+#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)
 extern char    *getcwd();
 #else
 extern char    *getwd();
@@ -56,6 +58,10 @@
 #if (defined(__linux__) && defined(__GLIBC__)) || defined(__CYGWIN__)
 /* martin.buck@bigfoot.com */
 #include <errno.h>
+#elif defined(__FreeBSD__)
+extern int    errno;
+extern const int sys_nerr;
+extern const char *const sys_errlist[];
 #else
 extern int      errno, sys_nerr;
 extern char    *sys_errlist[];
@@ -368,7 +374,7 @@
     }
 
 #ifdef		OW_I18N
-#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__)
+#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)
     if (getcwd(pathname_mb, MAXPATHLEN) == 0)
 #else
     if (getwd(pathname_mb) == 0)
@@ -378,7 +384,7 @@
 
 #else		/* OW_I18N */
 
-#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__)
+#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)
     if (getcwd(pathname, MAXPATHLEN) == 0)
 #else
     if (getwd(pathname) == 0)
@@ -1552,7 +1558,7 @@
     int             cmd_is_undo_all_edit;	/* This is for doing an "Undo
 						 * All edit" */
 {
-#ifndef SVR4
+#if !(defined(BSD4_4) && defined(SVR4))
     pkg_private Es_status textsw_checkpoint_internal();
 #else /* SVR4 */
     static Es_status textsw_checkpoint_internal();
@@ -2400,7 +2406,7 @@
     return (result);
 }
 
-#ifndef SVR4
+#if !(defined(BSD4_4) && defined(SVR4))
 Pkg_private     Es_status
 #else /* SVR4 */
 static     Es_status
