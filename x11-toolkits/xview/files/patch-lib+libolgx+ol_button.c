--- lib/libolgx/ol_button.c.orig	Mon Sep 29 00:02:39 2003
+++ lib/libolgx/ol_button.c	Mon Sep 29 00:02:39 2003
@@ -241,8 +241,12 @@
 				   x + ((centerx > 0) ? centerx : 0),
 				   y + ((centery > 0) ? centery : 0),
 				   (((Pixlabel *) label)->width > width)? 
-                                               width:((Pixlabel *)label)->width ,
-				  (height) ? height : Button_Height(info) - 2, state);
+						width:((Pixlabel *)label)->width ,
+				  (height) ? 
+				   ((((Pixlabel *) label)->height > height) ? 
+						 height : ((Pixlabel *)label)->height)
+ 					: Button_Height(info) - 2, state);
+ 
 	} else if (state & OLGX_LABEL_IS_XIMAGE) {
 
 	    int             centerx, centery;
@@ -255,7 +259,10 @@
 				   y + ((centery > 0) ? centery : 0),
 				   (((Pixlabel *) label)->width > width)? 
                                                width:((Pixlabel *)label)->width ,
-				  (height) ? height : Button_Height(info) - 2, state);
+				  (height) ? 
+				   ((((Pixlabel *) label)->height > height) ? 
+					       height : ((Pixlabel *)label)->height)
+					: Button_Height(info) - 2, state);
        } else {
 
 
