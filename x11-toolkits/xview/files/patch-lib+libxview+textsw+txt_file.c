--- lib/libxview/textsw/txt_file.c.orig	Tue Jun 29 00:17:48 1993
+++ lib/libxview/textsw/txt_file.c	Sun Oct  5 17:00:24 2003
@@ -18,10 +18,14 @@
 #include <xview_private/txt_impl.h>
 #include <xview_private/ev_impl.h>
 #include <xview_private/txt_18impl.h>
-#ifdef SVR4
+#include <sys/param.h>
+#if (defined(BSD4_4) || defined(SVR4))
 #include <dirent.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef BSD4_4
+#include <sys/file.h>
+#endif
 #else
 #include <sys/dir.h>
 #include <sys/file.h>
@@ -33,7 +37,6 @@
  */
 #undef MIN
 #undef MAX
-#include <sys/param.h>
 #include <xview/notice.h>
 #include <xview/frame.h>
 #include <errno.h>
@@ -45,13 +48,16 @@
 
 extern CHAR    *STRCAT();
 extern CHAR    *STRNCAT();
-#ifdef SVR4
+#if (defined(BSD4_4) || defined(SVR4))
 extern char    *getcwd();
 #else
 extern char    *getwd();
 #endif /* SVR4 */
-extern int      errno, sys_nerr;
-extern char    *sys_errlist[];
+extern int	errno;
+extern const int sys_nerr;
+#if (defined(BSD) && (BSD >= 199306))
+extern const char *const sys_errlist[];
+#endif /* BSD */
 
 Pkg_private int textsw_change_directory();
 Pkg_private void textsw_display(), textsw_display_view_margins();
@@ -354,7 +360,7 @@
     }
 
 #ifdef		OW_I18N
-#ifdef SVR4
+#if (defined(BSD4_4) || defined(SVR4)) 
     if (getcwd(pathname_mb, MAXPATHLEN) == 0)
 #else
     if (getwd(pathname_mb) == 0)
@@ -364,7 +370,7 @@
 
 #else		/* OW_I18N */
 
-#ifdef SVR4
+#if (defined(BSD4_4) || defined(SVR4)) 
     if (getcwd(pathname, MAXPATHLEN) == 0)
 #else
     if (getwd(pathname) == 0)
@@ -1538,7 +1544,7 @@
     int             cmd_is_undo_all_edit;	/* This is for doing an "Undo
 						 * All edit" */
 {
-#ifndef SVR4
+#if !(defined(BSD4_4) && defined(SVR4))
     pkg_private Es_status textsw_checkpoint_internal();
 #else /* SVR4 */
     static Es_status textsw_checkpoint_internal();
@@ -2386,7 +2392,7 @@
     return (result);
 }
 
-#ifndef SVR4
+#if !(defined(BSD4_4) && defined(SVR4))
 Pkg_private     Es_status
 #else /* SVR4 */
 static     Es_status
