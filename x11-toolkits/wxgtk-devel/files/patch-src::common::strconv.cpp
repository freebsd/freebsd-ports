
$FreeBSD$

--- src/common/strconv.cpp	2002/01/31 11:51:35	1.1
+++ src/common/strconv.cpp	2002/01/31 11:51:48
@@ -61,7 +61,7 @@
 #endif
 
 #ifdef HAVE_ICONV_H
-  #include <iconv.h>
+  #include <giconv.h>
 #endif
 
 #ifdef __WXMSW__
