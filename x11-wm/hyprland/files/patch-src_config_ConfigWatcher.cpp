--- src/config/ConfigWatcher.cpp.orig	2025-09-13 08:12:56 UTC
+++ src/config/ConfigWatcher.cpp
@@ -1,5 +1,7 @@
 #include "ConfigWatcher.hpp"
+#if defined(__linux__)
 #include <linux/limits.h>
+#endif
 #include <sys/inotify.h>
 #include "../debug/Log.hpp"
 #include <ranges>
