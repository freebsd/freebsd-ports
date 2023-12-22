--- goodies/appbar/image.cc.orig	2005-01-03 21:54:58 UTC
+++ goodies/appbar/image.cc
@@ -24,6 +24,7 @@
 #endif
 
 #include "image.hh"
+#include <cstdlib>
 
 #ifndef   MIN
 #  define MIN(a, b) ((a < b) ? a : b)
