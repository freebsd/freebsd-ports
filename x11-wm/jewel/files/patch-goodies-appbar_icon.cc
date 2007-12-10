--- goodies/appbar/icon.cc.orig	2007-12-06 21:09:37.000000000 +0100
+++ goodies/appbar/icon.cc	2007-12-06 21:15:12.000000000 +0100
@@ -35,7 +35,7 @@
 
 #include "icon.hh"
 
-char * default_icon_xpm[] = {
+const char * default_icon_xpm[] = {
 "16 16 16 1",
 " 	c None",
 ".	c #323232",
@@ -101,7 +101,7 @@
 	
 	if(! XpmCreatePixmapFromData(dpy, 
 		icon_win,
-		default_icon_xpm,
+		(char **)default_icon_xpm,
 		&icon_pixmap,
 		&icon_pixmap_mask,
 		&icon_pixmap_attr)==XpmSuccess)
@@ -165,7 +165,7 @@
 		
 		if(! XpmCreatePixmapFromData(dpy, 
 			icon_win,
-			default_icon_xpm,
+			(char **)default_icon_xpm,
 			&icon_pixmap,
 			&icon_pixmap_mask,
 			&icon_pixmap_attr)==XpmSuccess)
