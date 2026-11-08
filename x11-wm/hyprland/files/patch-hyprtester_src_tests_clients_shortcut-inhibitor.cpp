--- hyprtester/src/tests/clients/shortcut-inhibitor.cpp.orig	2026-11-03 09:47:41 UTC
+++ hyprtester/src/tests/clients/shortcut-inhibitor.cpp
@@ -10,6 +10,7 @@
 #include <optional>
 #include <format>
 #include <sys/poll.h>
+#include <unistd.h>
 #include <csignal>
 #include <thread>
 #include <filesystem>
