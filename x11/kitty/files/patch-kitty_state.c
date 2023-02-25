--- kitty/state.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/state.c
@@ -187,7 +187,7 @@ free_bgimage(BackgroundImage **bgimage, bool release_t
 }
 
 OSWindow*
-add_os_window() {
+add_os_window(void) {
     WITH_OS_WINDOW_REFS
     ensure_space_for(&global_state, os_windows, OSWindow, global_state.num_os_windows + 1, capacity, 1, true);
     OSWindow *ans = global_state.os_windows + global_state.num_os_windows++;
