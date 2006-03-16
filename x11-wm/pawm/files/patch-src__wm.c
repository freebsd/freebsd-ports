--- src/wm.c.orig	Fri Feb 24 05:12:18 2006
+++ src/wm.c	Sun Feb 26 03:10:37 2006
@@ -355,6 +355,9 @@
 	CARD32 tmpdata[20];
 	unsigned long length;
 	int (*olderrorhandler) (Display *, XErrorEvent *);
+#ifndef DISABLE_XRANDR
+	int major, minor,errbase;
+#endif
 
 	SAY ("Initializing window manager...");
 
@@ -373,7 +376,6 @@
 
 #ifndef DISABLE_XRANDR
 	/* Check for XRandr extension */
-	int major, minor,errbase;
 	XRRQueryVersion(display, &major, &minor);
 	XRRQueryExtension(display, &(class.randr_base), &errbase);
 	SAY("Using XRandr %d.%d extension. Event base: %d Error base %d", major, minor, class.randr_base, errbase);
