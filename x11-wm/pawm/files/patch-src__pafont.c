--- src/pafont.c.orig	Tue Jul 25 05:49:39 2006
+++ src/pafont.c	Fri Jul 28 16:28:48 2006
@@ -44,7 +44,7 @@
 }
 
 
-PAFont pafont_create(Display *dpy, const char* id)
+PAFont pafont_create(Display *dpy, Visual *visual, const char* id)
 {
 	PAFont xlfdfont;
 	char fontname[20];
@@ -86,7 +86,7 @@
 {
 	ASSERT(xlfdfont);
 
-	XSetForeground(xlfdfont->display, xgc, xfldfont->color);
+	XSetForeground(xlfdfont->display, xgc, xlfdfont->color);
 	/* X and Y coordinates mark the top left corner of the text box,
 	 * so we need to sum the ascent value to y to make the shitty old
 	 * X font system draw the text at the right place */
@@ -149,7 +149,7 @@
 	XColor ecolor, scolor;
 
 	XAllocNamedColor(xlfdfont->display, COLORMAP, name, &scolor, &ecolor);
-	xfldfont->color=scolor.pixel;
+	xlfdfont->color=scolor.pixel;
 }
 
 #else
