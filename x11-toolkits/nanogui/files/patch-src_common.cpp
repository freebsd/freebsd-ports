--- src/common.cpp.orig	2026-09-27 03:42:41 UTC
+++ src/common.cpp
@@ -27,7 +27,7 @@
 #elif defined(_WIN32)
 #  define GLFW_EXPOSE_NATIVE_WIN32
 #else
-#  define GLFW_EXPOSE_NATIVE_WAYLAND
+//#  define GLFW_EXPOSE_NATIVE_WAYLAND
 #  define GLFW_EXPOSE_NATIVE_X11
 #endif
 
