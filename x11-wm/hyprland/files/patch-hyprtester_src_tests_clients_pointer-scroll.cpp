--- hyprtester/src/tests/clients/pointer-scroll.cpp.orig	2026-01-04 11:40:44 UTC
+++ hyprtester/src/tests/clients/pointer-scroll.cpp
@@ -7,6 +7,7 @@
 #include <hyprutils/os/FileDescriptor.hpp>
 #include <hyprutils/os/Process.hpp>
 
+#include <unistd.h>
 #include <sys/poll.h>
 #include <csignal>
 #include <thread>
