--- include/common.hpp.orig	2020-12-02 17:15:49 UTC
+++ include/common.hpp
@@ -5,6 +5,9 @@
 #include <vector>
 #include <functional>
 
+#include <sys/types.h>
+#include <unistd.h>
+
 #include "settings.hpp"
 
 #define POLYBAR_NS    \
