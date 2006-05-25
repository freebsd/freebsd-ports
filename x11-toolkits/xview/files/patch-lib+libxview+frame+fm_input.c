--- lib/libxview/frame/fm_input.c.orig	Sat Mar 25 23:39:23 2006
+++ lib/libxview/frame/fm_input.c	Sat Mar 25 23:42:06 2006
@@ -359,6 +359,7 @@
  */
 Xv_private	void
 frame_set_accept_default_focus(frame_public, flag)
+	Frame frame_public;
 {
     Frame_class_info *frame = FRAME_CLASS_PRIVATE(frame_public);
 
