This is needed for compiling on FreeBSD >= 11.0.
--- backend/include/ICore.hh.orig	2022-04-01 16:28:54 UTC
+++ backend/include/ICore.hh
@@ -21,6 +21,7 @@
 #define ICORE_HH
 
 #include <string>
+#include <ctime>
 #include <iostream>
 
 #include "enum.h"
