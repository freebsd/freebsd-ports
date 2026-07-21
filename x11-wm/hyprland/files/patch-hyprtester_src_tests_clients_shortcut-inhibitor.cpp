--- hyprtester/src/tests/clients/shortcut-inhibitor.cpp.orig	2026-07-20 08:36:36 UTC
+++ hyprtester/src/tests/clients/shortcut-inhibitor.cpp
@@ -9,6 +9,7 @@
 
 #include <optional>
 #include <sys/poll.h>
+#include <unistd.h>
 #include <csignal>
 #include <thread>
 #include <filesystem>
