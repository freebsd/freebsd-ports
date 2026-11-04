--- hyprtester/src/tests/clients/fullscreen-with-monitor.cpp.orig	2026-11-04 06:41:47 UTC
+++ hyprtester/src/tests/clients/fullscreen-with-monitor.cpp
@@ -6,6 +6,7 @@
 #include <hyprutils/os/Process.hpp>
 #include <optional>
 #include <sys/poll.h>
+#include <unistd.h>
 #include <csignal>
 #include <thread>
 #include "tests.hpp"
