--- lib/libxview/screen/scrn_get.c.orig	Sat Mar 25 23:20:12 2006
+++ lib/libxview/screen/scrn_get.c	Sat Mar 25 23:20:44 2006
@@ -20,6 +20,7 @@
 #include <xview/base.h>
 #include <xview/font.h>
 #include <xview/server.h>
+#include <X11/Xlibint.h>
 
 /* Bitmap used for the inactive GC */
 static unsigned short screen_gray50_bitmap[16] = {   /* 50% gray pattern */
