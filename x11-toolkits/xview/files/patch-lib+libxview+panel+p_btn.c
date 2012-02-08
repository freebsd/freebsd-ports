--- lib/libxview/panel/p_btn.c.orig	2005-03-28 06:40:39.000000000 -0800
+++ lib/libxview/panel/p_btn.c	2012-02-03 08:25:38.585429214 -0800
@@ -203,12 +203,16 @@
 	if (pin_is_default) {
 	    image.im_type = PIT_STRING;
 	    image_string(&image) = NULL;
+#ifdef __FreeBSD__
+	    label = (Xv_opaque) "";
+#else
 /* Alpha compatibility, mbuck@debian.org */
 #if 1
 	    label = (char *)"";
 #else
 	    label = "";
 #endif
+#endif
 	} else if (!(image_string(&image) = (char *) xv_get(default_menu_item,
 		MENU_STRING))) {
 	    olgx_state |= OLGX_LABEL_IS_PIXMAP;
