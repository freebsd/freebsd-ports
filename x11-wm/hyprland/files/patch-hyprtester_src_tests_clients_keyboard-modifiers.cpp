--- hyprtester/src/tests/clients/keyboard-modifiers.cpp.orig	2026-06-11 08:27:50 UTC
+++ hyprtester/src/tests/clients/keyboard-modifiers.cpp
@@ -8,6 +8,7 @@
 
 #include <optional>
 #include <sys/poll.h>
+#include <unistd.h>
 #include <csignal>
 #include <thread>
 
