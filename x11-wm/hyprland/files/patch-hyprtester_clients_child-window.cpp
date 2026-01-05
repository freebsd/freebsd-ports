--- hyprtester/clients/child-window.cpp.orig	2026-01-04 11:44:08 UTC
+++ hyprtester/clients/child-window.cpp
@@ -3,6 +3,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <stdio.h>
+#include <unistd.h>
 
 #include <wayland-client.h>
 #include <wayland.hpp>
@@ -332,4 +333,4 @@ int main(int argc, char** argv) {
 
     wl_display_disconnect(display);
     return 0;
-}
\ No newline at end of file
+}
