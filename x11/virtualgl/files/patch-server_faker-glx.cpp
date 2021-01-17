--- server/faker-glx.cpp.orig	2019-10-20 21:29:00 UTC
+++ server/faker-glx.cpp
@@ -2192,11 +2192,10 @@ void glXQueryDrawable(Display *dpy, GLXDrawable draw, 
 	CATCH();
 }
 
-int glXQueryGLXPbufferSGIX(Display *dpy, GLXPbuffer pbuf, int attribute,
+void glXQueryGLXPbufferSGIX(Display *dpy, GLXPbuffer pbuf, int attribute,
 	unsigned int *value)
 {
 	glXQueryDrawable(dpy, pbuf, attribute, value);
-	return 0;
 }
 
 
@@ -2359,7 +2358,7 @@ void glXSwapBuffers(Display *dpy, GLXDrawable drawable
 // Returns the transparent index from the overlay visual on the 2D X server
 
 int glXGetTransparentIndexSUN(Display *dpy, Window overlay, Window underlay,
-	long *transparentIndex)
+	unsigned long *transparentIndex)
 {
 	int retval = False;
 	XWindowAttributes xwa;
