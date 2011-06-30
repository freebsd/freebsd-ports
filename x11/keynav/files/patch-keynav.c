--- ./keynav.c.orig	2011-06-29 20:24:04.335382341 -0400
+++ ./keynav.c	2011-06-29 21:21:31.846377864 -0400
@@ -10,6 +10,7 @@
 #include <unistd.h>
 #include <string.h>
 #include <errno.h>
+#include <ctype.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <signal.h>
@@ -174,6 +175,8 @@
 void query_screen_normal();
 int viewport_sort(const void *a, const void *b);
 int query_current_screen();
+int query_current_screen_xinerama();
+int query_current_screen_normal();
 void viewport_left();
 void viewport_right();
 int pointinrect(int px, int py, int rx, int ry, int rw, int rh);
@@ -1029,7 +1032,8 @@
   Window curwin;
   Window rootwin;
   Window dummy_win;
-  int x, y, width, height, border_width, depth;
+  int x, y;
+  unsigned int width, height, border_width, depth;
 
   xdo_window_get_active(xdo, &curwin);
   XGetGeometry(xdo->xdpy, curwin, &rootwin, &x, &y, &width, &height,
@@ -1469,7 +1473,7 @@
 
   //printf("Recording as keycode:%d\n", e->keycode);
   active_recording->keycode = e->keycode;
-  return;
+  return HANDLE_CONTINUE;
 }
 
 handler_info_t handle_gridnav(XKeyEvent *e) {
