--- lib/libxview/frame/fm_rescale.c.orig	2005-03-28 06:41:27.000000000 -0800
+++ lib/libxview/frame/fm_rescale.c	2012-02-02 17:20:51.135422700 -0800
@@ -43,7 +43,7 @@
      */
     window_default_event_func(frame_public, (Event *) 0, scale, (Notify_event_type) 0);
     window_calculate_new_size(frame_public, frame_public, &frame_height, &frame_width);
-#if !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__)
     xv_set(frame_public, WIN_RECT, 0); /* This looks like a XView bug to me */
 #endif
 
