This is needed for compiling on FreeBSD >= 11.0.
--- backend/include/ICore.hh.orig	2016-08-03 13:08:26 UTC
+++ backend/include/ICore.hh
@@ -21,6 +21,7 @@
 #define ICORE_HH
 
 #include <string>
+#include <ctime>
 
 #include "enum.h"
 
