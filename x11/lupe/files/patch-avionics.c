--- avionics.c.orig	1999-05-29 18:08:12.000000000 +0900
+++ avionics.c	2012-10-07 20:03:12.000000000 +0900
@@ -16,6 +16,10 @@
 #include <stdlib.h>
 #endif
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 #include "extern.h"
 #include "timer.h"
 
