--- programs/xdm/config/Xres.cpp.orig	Sat Jan  3 15:50:37 2004
+++ programs/xdm/config/Xres.cpp	Sat Jan  3 15:53:22 2004
@@ -28,7 +28,7 @@
 #endif /* XPM */
 xlogin*fail: Login incorrect
 #ifdef XPM
-/**/#if WIDTH > 800
+XHASHif WIDTH > 800
 xlogin*greetFont: -adobe-helvetica-bold-o-normal--24-240-75-75-p-138-iso8859-1
 xlogin*font: -adobe-helvetica-medium-r-normal--18-180-75-75-p-98-iso8859-1
 xlogin*promptFont: -adobe-helvetica-bold-r-normal--18-180-75-75-p-103-iso8859-1
@@ -38,9 +38,9 @@
 xlogin*font: -adobe-helvetica-medium-r-normal--12-120-75-75-p-67-iso8859-1
 xlogin*promptFont: -adobe-helvetica-bold-r-normal--12-120-75-75-p-70-iso8859-1
 xlogin*failFont: -adobe-helvetica-bold-o-normal--14-140-75-75-p-82-iso8859-1
-/**/#endif
+XHASHendif
 #endif /* XPM */
-/**/#ifdef COLOR
+XHASHifdef COLOR
 #ifndef XPM
 xlogin*greetColor: CadetBlue
 #else
@@ -56,7 +56,7 @@
 xlogin*failColor: red
 *Foreground: black
 *Background: #fffff0
-/**/#else
+XHASHelse
 #ifdef XPM
 xlogin*borderWidth: 3
 xlogin*frameWidth: 0
@@ -68,13 +68,13 @@
 xlogin*Foreground: black
 xlogin*Background: white
 #endif /* XPM */
-/**/#endif
+XHASHendif
 #ifdef XPM
-/**/#if PLANES >= 8
+XHASHif PLANES >= 8
 xlogin*logoFileName: BITMAPDIR/**//XDM_PIXMAP
-/**/#else
+XHASHelse
 xlogin*logoFileName: BITMAPDIR/**//XDM_BWPIXMAP
-/**/#endif
+XHASHendif
 xlogin*useShape: true
 xlogin*logoPadding: 10
 #endif /* XPM */
