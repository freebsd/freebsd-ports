--- hyprtester/clients/shortcut-inhibitor.cpp.orig	2026-03-02 07:58:44 UTC
+++ hyprtester/clients/shortcut-inhibitor.cpp
@@ -1,6 +1,7 @@
 #include <sys/poll.h>
 #include <sys/mman.h>
 #include <fcntl.h>
+#include <unistd.h>
 #include <print>
 
 #include <wayland-client.h>
