--- WINGs/WINGs/WINGsP.h.orig	2015-08-11 18:41:14 UTC
+++ WINGs/WINGs/WINGsP.h
@@ -17,7 +17,13 @@
 
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
