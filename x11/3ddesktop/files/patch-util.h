--- util.h.orig	Mon May 10 00:57:26 2004
+++ util.h	Thu Aug 26 23:00:45 2004
@@ -21,7 +21,7 @@
 #ifndef _UTIL_H
 #define _UTIL_H
 #include <math.h>     // for cos
-#include <endian.h>
+#include <sys/endian.h>
 #include "3ddesk.h"
 
 #define MAX_FACES  30  // this is a lot
