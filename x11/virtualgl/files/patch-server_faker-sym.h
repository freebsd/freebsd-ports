--- server/faker-sym.h.orig	2019-10-20 21:29:00 UTC
+++ server/faker-sym.h
@@ -536,7 +536,7 @@ FUNCDEF2(GLXFBConfigSGIX, glXGetFBConfigFromVisualSGIX
 // GLX_SUN_get_transparent_index
 
 FUNCDEF4(int, glXGetTransparentIndexSUN, Display *, dpy, Window, overlay,
-	Window, underlay, long *, transparentIndex, glXGetTransparentIndexSUN);
+	Window, underlay, unsigned long *, transparentIndex, glXGetTransparentIndexSUN);
 
 
 // GL functions
