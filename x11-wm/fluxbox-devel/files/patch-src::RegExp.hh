--- src/RegExp.hh.orig	Thu Jul 10 23:39:07 2003
+++ src/RegExp.hh	Thu Jul 10 23:39:17 2003
@@ -39,8 +39,8 @@
  */
 
 #ifdef USE_REGEXP
-#include <regex.h>
 #include <sys/types.h>
+#include <regex.h>
 #endif // USE_REGEXP
 
 class WinClient;
