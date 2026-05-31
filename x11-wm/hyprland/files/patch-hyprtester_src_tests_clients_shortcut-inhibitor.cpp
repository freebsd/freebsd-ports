--- hyprtester/src/tests/clients/shortcut-inhibitor.cpp.orig	2026-05-31 08:23:05 UTC
+++ hyprtester/src/tests/clients/shortcut-inhibitor.cpp
@@ -8,6 +8,7 @@
 
 #include <optional>
 #include <sys/poll.h>
+#include <unistd.h>
 #include <csignal>
 #include <thread>
 #include <filesystem>
