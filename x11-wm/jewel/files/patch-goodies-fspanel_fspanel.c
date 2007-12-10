--- goodies/fspanel/fspanel.c.orig	2007-12-06 22:35:02.000000000 +0100
+++ goodies/fspanel/fspanel.c	2007-12-06 22:37:02.000000000 +0100
@@ -393,7 +393,8 @@
 
 void scale_icon (task *tk)
 {
-	int xx, yy, x, y, w, h, d, bw;
+	int xx, yy, x, y;
+	unsigned int w, h, d, bw;
 	Pixmap pix, mk = None;
 	XGCValues gcv;
 	GC mgc=None;
