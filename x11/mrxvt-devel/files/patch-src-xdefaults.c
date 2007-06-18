--- src/xdefaults.c.orig	Sun Oct  1 23:50:37 2006
+++ src/xdefaults.c	Sat Jun 16 23:10:19 2007
@@ -234,9 +234,7 @@
     STRG(Rs_tabbarPixmap, "tabbarPixmap", "tbpixmap", "file[;geom]", "tabbar background image", 0),
     BOOL( "tabUsePixmap", "tupixmap", Opt_tabPixmap,
 	    "use tabbar background image for tabs" ),
-# if 0 /* App icon not yet implemented */
     STRG(Rs_appIcon, "appIcon", "ic", "file[;geom]", "application icon file", 0),
-#endif
 #endif	/* BACKGROUND_IMAGE */
 
     BOOL( "utmpInhibit", "ut", Opt_utmpInhibit,
