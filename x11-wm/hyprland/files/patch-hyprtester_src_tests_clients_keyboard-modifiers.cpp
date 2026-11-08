--- hyprtester/src/tests/clients/keyboard-modifiers.cpp.orig	2026-11-03 09:47:41 UTC
+++ hyprtester/src/tests/clients/keyboard-modifiers.cpp
@@ -9,6 +9,7 @@
 #include <optional>
 #include <format>
 #include <sys/poll.h>
+#include <unistd.h>
 #include <csignal>
 #include <thread>
 
