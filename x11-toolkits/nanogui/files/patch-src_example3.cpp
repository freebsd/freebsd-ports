--- src/example3.cpp.orig	2026-09-27 03:32:38 UTC
+++ src/example3.cpp
@@ -167,7 +167,7 @@ int main(int /* argc */, char ** /* argv */) {
     );
 
     glfwSetScrollCallback(window,
-        [](GLFWwindow *, double x, double y) {
+        [](GLFWwindow *, double x, double y, int dummy) {
             screen->scroll_callback_event(x, y);
        }
     );
