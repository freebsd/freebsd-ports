--- ./lib/libxview/panel/p_btn.c.orig	Tue Jun 29 07:16:52 1993
+++ ./lib/libxview/panel/p_btn.c	Sat Apr  1 18:25:26 2000
@@ -203,7 +203,7 @@ btn_begin_preview(item_public, event)
 	if (pin_is_default) {
 	    image.im_type = PIT_STRING;
 	    image_string(&image) = NULL;
-	    label = "";
+	    label = (Xv_opaque) "";
 	} else if (!(image_string(&image) = (char *) xv_get(default_menu_item,
 		MENU_STRING))) {
 	    olgx_state |= OLGX_LABEL_IS_PIXMAP;
