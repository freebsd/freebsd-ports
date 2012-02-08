--- lib/libxview/notify/ndet_fd.c.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/ndet_fd.c	2012-02-02 20:58:01.499747999 -0800
@@ -27,8 +27,9 @@
 #define GETDTABLESIZE() \
 (dtablesize_cache?dtablesize_cache:(dtablesize_cache=(int)sysconf(_SC_OPEN_MAX)))
 #else
-#define GETDTABLESIZE() \
-    (dtablesize_cache?dtablesize_cache:(dtablesize_cache=getdtablesize()))
+#define GETDTABLESIZE()                                               \
+    (dtablesize_cache ? dtablesize_cache :                    \
+    (dtablesize_cache = MIN(getdtablesize(), FD_SETSIZE)))
 #endif /* SVR4 */
 
 static int      ndet_fd_table_size;	/* Number of descriptor slots
