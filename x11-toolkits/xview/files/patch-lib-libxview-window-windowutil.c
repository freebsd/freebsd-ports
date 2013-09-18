--- lib/libxview/window/windowutil.c.orig	2013-09-17 22:36:32.330750964 -0700
+++ lib/libxview/window/windowutil.c	2013-09-17 22:38:48.691209544 -0700
@@ -767,7 +767,7 @@
 
 	adjust_rect_obj(num_elems, this_sw, rect_obj_list, parent_width, parent_height);
 	window_outer_to_innerrect(&(rect_obj_list[this_sw]),
-				  rect_obj_list[this_sw].new_rect);
+				  &(rect_obj_list[this_sw].new_rect));
     }
 }
 
