--- goodies/appbar/image.cc.orig	2013-09-26 16:59:32.000000000 +0200
+++ goodies/appbar/image.cc	2013-09-26 17:00:23.000000000 +0200
@@ -24,6 +24,7 @@
 #endif
 
 #include "image.hh"
+#include <cstdlib>
 
 #ifndef   MIN
 #  define MIN(a, b) ((a < b) ? a : b)
