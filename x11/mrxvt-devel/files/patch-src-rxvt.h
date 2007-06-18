--- src/rxvt.h.orig	Sun Oct  1 23:50:38 2006
+++ src/rxvt.h	Sat Jun 16 23:10:15 2007
@@ -1109,9 +1109,7 @@
 
 #ifdef BACKGROUND_IMAGE
     Rs_tabbarPixmap,	/* tabbar background pixmap */
-# if 0 /* appicon not yet implemented */
     Rs_appIcon,		/* use pixmap as application icon */
-# endif
 #endif
 
 #ifdef HAVE_MENUBAR
@@ -1704,6 +1702,10 @@
 							   succesfully grabbed
 							   at prevPos */
 #endif
+
+    Pixmap          appIcon;
+    Pixmap          appIconMask;
+
 };
 
 #ifndef __attribute__
