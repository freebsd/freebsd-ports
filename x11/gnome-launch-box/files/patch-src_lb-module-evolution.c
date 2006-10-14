--- src/lb-module-evolution.c.orig	Sat Sep 30 02:32:56 2006
+++ src/lb-module-evolution.c	Sat Sep 30 02:33:58 2006
@@ -258,8 +258,8 @@
 
 			g_print ("Loading image\n");
 			loader = gdk_pixbuf_loader_new ();
-			gdk_pixbuf_loader_write (loader, photo->data, 
-						 photo->length, NULL);
+			gdk_pixbuf_loader_write (loader, photo->data.inlined.data, 
+						 photo->data.inlined.length, NULL);
 			pixbuf = gdk_pixbuf_loader_get_pixbuf (loader);
 			if (pixbuf) {
 				g_object_set (item,
