Index: xdriinfo.c
===================================================================
RCS file: /cvs/xorg/xc/programs/xdriinfo/xdriinfo.c,v
retrieving revision 1.1.3.1
diff -u -r1.1.3.1 xdriinfo.c
--- programs/xdriinfo/xdriinfo.c	16 Jun 2004 09:27:39 -0000	1.1.3.1
+++ programs/xdriinfo/xdriinfo.c	23 Nov 2005 04:40:38 -0000
@@ -22,6 +22,7 @@
  * 
  */
 
+#define GLX_GLXEXT_LEGACY
 #include <GL/glx.h>
 #include <X11/Xlib.h>
 #include <stdio.h>
@@ -57,8 +58,8 @@
     char *funcArg = NULL;
     char *dpyName = NULL;
 
-    GetScreenDriver = (glXGetScreenDriver_t *)glXGetProcAddress ("glXGetScreenDriver");
-    GetDriverConfig = (glXGetDriverConfig_t *)glXGetProcAddress ("glXGetDriverConfig");
+    GetScreenDriver = (glXGetScreenDriver_t *)glXGetProcAddressARB ("glXGetScreenDriver");
+    GetDriverConfig = (glXGetDriverConfig_t *)glXGetProcAddressARB ("glXGetDriverConfig");
     if (!GetScreenDriver || !GetDriverConfig) {
 	fprintf (stderr, "libGL is too old.\n");
 	return 1;
