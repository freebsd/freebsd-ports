--- hyprtester/clients/fullscreen-with-monitor.cpp.orig	2026-11-04 06:41:24 UTC
+++ hyprtester/clients/fullscreen-with-monitor.cpp
@@ -7,6 +7,7 @@
 #include <print>
 #include <format>
 #include <string>
+#include <span>
 
 #include <wayland-client.h>
 #include <wayland.hpp>
@@ -232,4 +233,4 @@ int main() {
     s                   = {};
     wl_display_disconnect(display);
     return 0;
-}
\ No newline at end of file
+}
