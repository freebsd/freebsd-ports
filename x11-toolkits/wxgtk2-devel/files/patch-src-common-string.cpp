--- src/common/string.cpp.orig	Mon Feb 21 15:53:48 2005
+++ src/common/string.cpp	Tue Feb 22 01:39:54 2005
@@ -39,6 +39,7 @@
 #endif
 
 #include <ctype.h>
+#include <errno.h>
 #include <string.h>
 #include <stdlib.h>
 
@@ -1956,6 +1957,9 @@
             // ok, there was enough space
             break;
         }
+
+	if (errno != EOVERFLOW)
+            break;
 
         // still not enough, double it again
         size *= 2;
