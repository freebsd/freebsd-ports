--- goodies/setrootimage/image.cc.orig	2013-09-26 17:16:12.000000000 +0200
+++ goodies/setrootimage/image.cc	2013-09-26 17:16:27.000000000 +0200
@@ -24,6 +24,7 @@
 #endif
 
 #include "image.hh"
+#include <cstdlib>
 
 #ifndef   MIN
 #  define MIN(a, b) ((a < b) ? a : b)
