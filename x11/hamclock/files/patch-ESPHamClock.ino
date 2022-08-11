--- ESPHamClock.ino.orig	2022-04-30 15:37:10.367129000 -0500
+++ ESPHamClock.ino	2022-04-30 15:37:48.165833000 -0500
@@ -1,6 +1,9 @@
 /* HamClock
  */
 
+#if defined(__FreeBSD__)
+#include <execinfo.h>
+#endif
 
 // glue
 #include "HamClock.h"
