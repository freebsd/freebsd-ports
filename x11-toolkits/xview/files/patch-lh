--- ../alt/lib/libxview/notify/ndisdispch.c	Tue Jun 29 07:18:06 1993
+++ lib/libxview/notify/ndisdispch.c	Sat Jul 26 00:55:47 1997
@@ -30,8 +30,9 @@
 #define GETDTABLESIZE() \
 (dtablesize_cache?dtablesize_cache:(dtablesize_cache=(int)sysconf(_SC_OPEN_MAX)))
 #else
-#define GETDTABLESIZE() \
- (dtablesize_cache?dtablesize_cache:(dtablesize_cache=getdtablesize()))
+#define GETDTABLESIZE()						\
+    (dtablesize_cache ? dtablesize_cache :			\
+    (dtablesize_cache = MIN(getdtablesize(), FD_SETSIZE)))
 #endif SVR4
 
 pkg_private_data u_int ndis_flags = 0;
