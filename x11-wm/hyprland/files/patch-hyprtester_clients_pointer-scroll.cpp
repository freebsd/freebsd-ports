--- hyprtester/clients/pointer-scroll.cpp.orig	2026-01-04 11:43:28 UTC
+++ hyprtester/clients/pointer-scroll.cpp
@@ -2,6 +2,7 @@
 #include <sys/poll.h>
 #include <sys/mman.h>
 #include <fcntl.h>
+#include <unistd.h>
 #include <print>
 #include <format>
 #include <string>
