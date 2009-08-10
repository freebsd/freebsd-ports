--- ./cmake/modules/FindKexiv2.cmake.orig	2009-01-06 17:27:37.000000000 +0000
+++ ./cmake/modules/FindKexiv2.cmake	2009-01-25 08:34:53.000000000 +0000
@@ -49,7 +49,7 @@
       # in the FIND_PATH() and FIND_LIBRARY() calls
       INCLUDE(UsePkgConfig)
     
-      PKGCONFIG(libkexiv2 _KEXIV2IncDir _KEXIV2LinkDir _KEXIV2LinkFlags _KEXIV2Cflags)
+      PKGCONFIG(libkexiv2-kde4 _KEXIV2IncDir _KEXIV2LinkDir _KEXIV2LinkFlags _KEXIV2Cflags)
     
       if(_KEXIV2LinkFlags)
         # query pkg-config asking for a libkexiv2 >= 0.2.0
