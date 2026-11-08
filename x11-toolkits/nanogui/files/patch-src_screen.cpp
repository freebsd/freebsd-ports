--- src/screen.cpp.orig	2026-09-27 03:01:49 UTC
+++ src/screen.cpp
@@ -378,7 +378,7 @@ Screen::Screen(const Vector2i &size, std::string_view 
     );
 
     glfwSetScrollCallback(m_glfw_window,
-        [](GLFWwindow *w, double x, double y) {
+        [](GLFWwindow *w, double x, double y, int dummy) {
             for (auto kv: __nanogui_screens) {
                 if (w == kv.first) {
                     kv.second->scroll_callback_event(x, y);
