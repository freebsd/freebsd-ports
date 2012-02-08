--- lib/libxview/notify/ndisdispch.c.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/ndisdispch.c	2012-02-02 21:19:12.920272396 -0800
@@ -30,8 +30,9 @@
 #define GETDTABLESIZE() \
 (dtablesize_cache?dtablesize_cache:(dtablesize_cache=(int)sysconf(_SC_OPEN_MAX)))
 #else
-#define GETDTABLESIZE() \
- (dtablesize_cache?dtablesize_cache:(dtablesize_cache=getdtablesize()))
+#define GETDTABLESIZE()                                               \
+    (dtablesize_cache ? dtablesize_cache :                    \
+    (dtablesize_cache = MIN(getdtablesize(), FD_SETSIZE)))
 #endif /* SVR4 */
 
 pkg_private_data u_int ndis_flags = 0;
