--- include/common.hpp.orig	2023-11-05 22:37:13 UTC
+++ include/common.hpp
@@ -6,6 +6,9 @@
 #include <type_traits>
 #include <vector>
 
+#include <sys/types.h>
+#include <unistd.h>
+
 #include "settings.hpp"
 
 #define POLYBAR_NS namespace polybar {
