--- src/sawmill.h.orig      Mon Jan 13 05:35:23 2003
+++ src/sawmill.h   Mon May  8 11:52:40 2006
@@ -153,7 +153,7 @@
     /* Frame data */
     Window frame;
     struct frame_part *frame_parts;
-    u_int frame_x, frame_y;            /* relative to client-window */
+    int frame_x, frame_y;              /* relative to client-window */
     u_int frame_width, frame_height;
     void (*destroy_frame)(struct lisp_window *w);
     void (*focus_change)(struct lisp_window *w);
