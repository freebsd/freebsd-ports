--- ./lib/libxview/file_chooser/fc_layout.c.orig	Tue Jun 29 07:17:55 1993
+++ ./lib/libxview/file_chooser/fc_layout.c	Sat Apr  1 18:25:23 2000
@@ -464,8 +464,8 @@ file_chooser_position_objects( private )
 
 	new_height 
 	    = (* private->exten_func)( FC_PUBLIC(private),
-				      private->rect,
-				      exten_rect,
+				      &private->rect,
+				      &exten_rect,
 				      COLS(2),
 				      private->rect.r_width - COLS(2),
 				      max_height
