--- src/wayland/buffer/dmabuf.cpp.orig	2026-05-09 11:41:19 UTC
+++ src/wayland/buffer/dmabuf.cpp
@@ -37,7 +37,9 @@
 #include <qwaylandclientextension.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
+#if defined(__linux__)
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #include <vulkan/vulkan_core.h>
