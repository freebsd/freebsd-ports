--- ext/glfw/src/platform.h.orig	2026-09-27 03:40:45 UTC
+++ ext/glfw/src/platform.h
@@ -69,7 +69,7 @@
 
 #if defined(_GLFW_WAYLAND)
  #include "wl_platform.h"
- #define GLFW_EXPOSE_NATIVE_WAYLAND
+ //#define GLFW_EXPOSE_NATIVE_WAYLAND
 #else
  #define GLFW_WAYLAND_WINDOW_STATE
  #define GLFW_WAYLAND_MONITOR_STATE
