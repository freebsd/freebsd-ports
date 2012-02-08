--- lib/libxview/textsw/txt_filter.c.orig	2005-03-28 06:40:33.000000000 -0800
+++ lib/libxview/textsw/txt_filter.c	2012-02-03 10:15:09.976397060 -0800
@@ -17,7 +17,7 @@
 #include <sys/types.h>
 #include <sys/file.h>
 #include <unistd.h>
-#if defined SVR4 || defined __CYGWIN__
+#if defined SVR4 || defined __CYGWIN__ || defined __FreeBSD__
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -38,7 +38,7 @@
 #include <vfork.h>
 #endif /* SVR4 */
 #endif
-#if defined(__linux__) || defined(__CYGWIN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined __FreeBSD__
 #include <unistd.h>
 #endif
 #include <sys/errno.h>
@@ -58,6 +58,9 @@
 #define	REPLY_OKAY	 0
 #define	REPLY_SEND	 1
 
+static int	talk_to_filter();
+static int	start_filter();
+
 /* performance: global cache of getdtablesize() */
 extern int      dtablesize_cache;
 
