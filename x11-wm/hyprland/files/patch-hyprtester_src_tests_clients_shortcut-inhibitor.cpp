--- hyprtester/src/tests/clients/shortcut-inhibitor.cpp.orig	2026-03-02 07:56:10 UTC
+++ hyprtester/src/tests/clients/shortcut-inhibitor.cpp
@@ -7,6 +7,7 @@
 #include <hyprutils/os/FileDescriptor.hpp>
 #include <hyprutils/os/Process.hpp>
 
+#include <unistd.h>
 #include <sys/poll.h>
 #include <csignal>
 #include <thread>
