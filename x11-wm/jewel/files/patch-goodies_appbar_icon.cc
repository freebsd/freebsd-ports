--- goodies/appbar/icon.cc.orig	2005-01-03 21:54:58 UTC
+++ goodies/appbar/icon.cc
@@ -35,7 +35,7 @@
 
 #include "icon.hh"
 
-char * default_icon_xpm[] = {
+const char * default_icon_xpm[] = {
 "16 16 16 1",
 " 	c None",
 ".	c #323232",
@@ -101,7 +101,7 @@ Icon::Icon(Display *d, Window parent)
 	
 	if(! XpmCreatePixmapFromData(dpy, 
 		icon_win,
-		default_icon_xpm,
+		(char **)default_icon_xpm,
 		&icon_pixmap,
 		&icon_pixmap_mask,
 		&icon_pixmap_attr)==XpmSuccess)
@@ -165,7 +165,7 @@ bool Icon::loadPixmap(std::string iconFilename)
 		
 		if(! XpmCreatePixmapFromData(dpy, 
 			icon_win,
-			default_icon_xpm,
+			(char **)default_icon_xpm,
 			&icon_pixmap,
 			&icon_pixmap_mask,
 			&icon_pixmap_attr)==XpmSuccess)
