--- config/Xresources.cpp.orig	2012-09-27 10:41:28.000000000 +0200
+++ config/Xresources.cpp	2012-09-27 10:41:56.000000000 +0200
@@ -60,9 +60,9 @@
 XHASHendif
 #ifdef XPM
 XHASHif PLANES >= 8
-xlogin*logoFileName: BITMAPDIR/**//XDM_PIXMAP
+xlogin*logoFileName: BITMAPDIR/XDM_PIXMAP
 XHASHelse
-xlogin*logoFileName: BITMAPDIR/**//XDM_BWPIXMAP
+xlogin*logoFileName: BITMAPDIR/XDM_BWPIXMAP
 XHASHendif
 xlogin*useShape: true
 xlogin*logoPadding: 10
