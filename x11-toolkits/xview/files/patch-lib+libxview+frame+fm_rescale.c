--- lib/libxview/frame/fm_rescale.c.orig	Sat Oct  4 19:28:47 2003
+++ lib/libxview/frame/fm_rescale.c	Sat Oct  4 19:31:47 2003
@@ -43,7 +43,7 @@
      */
     window_default_event_func(frame_public, (Event *) 0, scale, (Notify_event_type) 0);
     window_calculate_new_size(frame_public, frame_public, &frame_height, &frame_width);
-    xv_set(frame_public, WIN_RECT, 0);
+	/* xv_set(frame_public, WIN_RECT, 0); */
 
 
     /*
