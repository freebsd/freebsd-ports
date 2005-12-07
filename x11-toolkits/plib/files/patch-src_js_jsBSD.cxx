--- src/js/jsBSD.cxx.orig	Wed Jan 12 02:22:26 2005
+++ src/js/jsBSD.cxx	Wed Dec  7 10:35:27 2005
@@ -44,6 +44,8 @@
 #define HAVE_USB_JS	1
 #endif
 
+#include <string.h>
+#include <errno.h>
 #include <sys/ioctl.h>
 #if defined(__FreeBSD__)
 # include <sys/joystick.h>
@@ -312,7 +314,7 @@
     int buttons [ _JS_MAX_AXES ] ;
   
     rawRead ( buttons, axes ) ;
-    error = axes[0] < -1000000000.0f ;
+    error = axes[0] < -1000000000.0f && axes[1] < -1000000000.0f ;
     if ( error )
       return ;
   
@@ -321,7 +323,11 @@
     joyfile = fopen ( joyfname, "r" ) ;
     error = ( joyfile == NULL ) ;
     if ( error )
+    {
+      ulSetError ( UL_WARNING, "unable to open calibration file %s (%s), joystick %i disabled (you can generate the calibration file with the plib-jscal utility)",
+		   joyfname, strerror ( errno ), id + 1 );
       return ;
+    }
 
     noargs = fscanf ( joyfile, "%d%f%f%f%f%f%f", &in_no_axes,
                       &min [ 0 ], &center [ 0 ], &max [ 0 ],
@@ -445,8 +451,13 @@
 
     if ( axes != NULL )
     {
-      axes[0] = (float) os->ajs.x ;
-      axes[1] = (float) os->ajs.y ;
+      if ( os->ajs.x >= -1000000000 )
+	os->cache_axes[0] = os->ajs.x;
+      if ( os->ajs.y >= -1000000000 )
+	os->cache_axes[1] = os->ajs.y;
+
+      axes[0] = os->cache_axes[0];
+      axes[1] = os->cache_axes[1];
     }
 
     return;
