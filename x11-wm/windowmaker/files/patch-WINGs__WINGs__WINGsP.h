--- WINGs/WINGs/WINGsP.h.orig	2013-03-06 03:52:04.000000000 +0900
+++ WINGs/WINGs/WINGsP.h	2013-03-06 03:51:32.000000000 +0900
@@ -14,7 +14,13 @@
 
 #include <assert.h>
 
+#ifdef _XLOCALE_H_	/* workaround for libX11<1.4 */
+#undef _XLOCALE_H_
+#include <stdlib.h>
+#define _XLOCALE_H_
+#else
 #include <stdlib.h>
+#endif
 #include <string.h>
 #include <strings.h>
 #include <stdio.h>
