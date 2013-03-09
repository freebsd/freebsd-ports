--- ./src/xfce-backdrop.c.orig	2013-03-02 16:42:00.000000000 +0000
+++ ./src/xfce-backdrop.c	2013-03-07 19:23:41.000000000 +0000
@@ -924,6 +924,8 @@
 xfce_backdrop_get_pixbuf(XfceBackdrop *backdrop)
 {
     GdkPixbuf *final_image, *image = NULL, *tmp;
+    GdkPixbufFormat *format = NULL;
+    gboolean apply_backdrop_image = FALSE;
     gint i, j;
     gint w, h, iw = 0, ih = 0;
     XfceBackdropImageStyle istyle;
@@ -933,8 +935,12 @@
     
     g_return_val_if_fail(XFCE_IS_BACKDROP(backdrop), NULL);
     
-    if(backdrop->priv->show_image && backdrop->priv->image_path)
-        gdk_pixbuf_get_file_info(backdrop->priv->image_path, &iw, &ih);
+    if(backdrop->priv->show_image && backdrop->priv->image_path) {
+        format = gdk_pixbuf_get_file_info(backdrop->priv->image_path, &iw, &ih);
+        /* make sure we have a usable backdrop image */
+        if(format != NULL)
+            apply_backdrop_image = TRUE;
+    }
 
     if(backdrop->priv->width == 0 || backdrop->priv->height == 0) {
         w = iw;
@@ -956,9 +962,7 @@
             final_image = create_solid(&backdrop->priv->color1, w, h, FALSE, 0xff);
     }
     
-    /*check if the file exists,
-     *and if it doesn't then make the background the single colour*/
-    if(!g_file_test(backdrop->priv->image_path, G_FILE_TEST_EXISTS)) {
+    if(!apply_backdrop_image) {
         if(backdrop->priv->brightness != 0)
             final_image = adjust_brightness(final_image, backdrop->priv->brightness);
         
