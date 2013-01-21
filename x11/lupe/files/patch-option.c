--- option.c.orig	1999-05-29 18:08:12.000000000 +0900
+++ option.c	2012-10-07 20:02:51.000000000 +0900
@@ -13,6 +13,10 @@
 #include <stdlib.h>
 #endif
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 #include "extern.h"
 
 #define OPT_FUNC	1
