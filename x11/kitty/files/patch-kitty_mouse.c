--- kitty/mouse.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/mouse.c
@@ -639,7 +639,7 @@ closest_window_for_event(unsigned int *window_idx) {
 }
 
 void
-focus_in_event() {
+focus_in_event(void) {
     // Ensure that no URL is highlighted and the mouse cursor is in default shape
     bool in_tab_bar;
     unsigned int window_idx = 0;
@@ -653,7 +653,7 @@ focus_in_event() {
 }
 
 void
-enter_event() {
+enter_event(void) {
 #ifdef __APPLE__
     // On cocoa there is no way to configure the window manager to
     // focus windows on mouse enter, so we do it ourselves
