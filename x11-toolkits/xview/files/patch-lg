--- ../alt/lib/libxview/notify/ndet_fd.c	Tue Jun 29 07:18:08 1993
+++ lib/libxview/notify/ndet_fd.c	Sat Jul 26 00:42:21 1997
@@ -27,8 +27,9 @@
 #define GETDTABLESIZE() \
 (dtablesize_cache?dtablesize_cache:(dtablesize_cache=(int)sysconf(_SC_OPEN_MAX)))
 #else
-#define GETDTABLESIZE() \
-    (dtablesize_cache?dtablesize_cache:(dtablesize_cache=getdtablesize()))
+#define GETDTABLESIZE()						\
+    (dtablesize_cache ? dtablesize_cache :			\
+    (dtablesize_cache = MIN(getdtablesize(), FD_SETSIZE)))
 #endif SVR4
 
 static int      ndet_fd_table_size;	/* Number of descriptor slots
