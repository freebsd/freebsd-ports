--- src/paicon.c.orig	Tue Jul  4 03:19:55 2006
+++ src/paicon.c	Mon Jul 17 03:27:59 2006
@@ -263,6 +263,9 @@
 {
 	PAIcon icon=NULL;
 
+	XSetWindowAttributes wattr;
+	unsigned long wmask;
+
 	ASSERT(image);
 
 	icon=malloc(PAIconBytes);
@@ -273,9 +276,6 @@
 #endif
 
 	icon->image=image;
-
-	XSetWindowAttributes wattr;
-	unsigned long wmask;
 
 	wattr.border_pixel=0;
 	wattr.colormap = XCreateColormap (display, ROOT, DEFAULTVISUAL, AllocNone);
