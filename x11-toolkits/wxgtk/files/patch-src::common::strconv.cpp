
$FreeBSD$

--- src/common/strconv.cpp	2002/09/09 13:18:00	1.1
+++ src/common/strconv.cpp	2002/09/09 13:18:10
@@ -358,7 +358,7 @@
 #if defined(__BORLANDC__) && (__BORLANDC__ > 0x530)
   return std::wcslen(psz);
 #else
-  return ::wcslen(psz);
+  return wcslen(psz);
 #endif
 }
 
