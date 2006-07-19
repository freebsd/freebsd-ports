--- src/button.c.orig	Tue Jul  4 03:19:55 2006
+++ src/button.c	Mon Jul 17 03:28:20 2006
@@ -247,6 +247,9 @@
 	XSetWindowAttributes attributes;
 	Button button=NULL;
 
+	XSetWindowAttributes wattr;
+	unsigned long wmask;
+
 	ASSERT(parent!=None);
 	ASSERT(nface!=None); 
 	ASSERT(hface!=None);
@@ -269,9 +272,6 @@
 
 
 	/** Window creation and basic setup **/
-
-	XSetWindowAttributes wattr;
-	unsigned long wmask;
 
 	wattr.border_pixel=0;
 	wattr.colormap = XCreateColormap (display, ROOT, DEFAULTVISUAL, AllocNone);
