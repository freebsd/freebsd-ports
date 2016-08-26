--- config/Xresources.cpp.orig	2011-09-25 07:35:47 UTC
+++ config/Xresources.cpp
@@ -60,9 +60,9 @@ xlogin*hiColor: black
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
