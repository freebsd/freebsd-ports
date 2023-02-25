--- kitty/glfw.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/glfw.c
@@ -176,7 +176,7 @@ log_event(const char *format, ...) {
 // callbacks {{{
 
 void
-update_os_window_references() {
+update_os_window_references(void) {
     for (size_t i = 0; i < global_state.num_os_windows; i++) {
         OSWindow *w = global_state.os_windows + i;
         if (w->handle) glfwSetWindowUserPointer(w->handle, w);
@@ -1395,7 +1395,7 @@ swap_window_buffers(OSWindow *os_window) {
 }
 
 void
-wakeup_main_loop() {
+wakeup_main_loop(void) {
     glfwPostEmptyEvent();
 }
 
