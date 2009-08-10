--- ./cmake/modules/FindKdcraw.cmake.orig	2009-01-06 17:27:37.000000000 +0000
+++ ./cmake/modules/FindKdcraw.cmake	2009-01-25 08:34:44.000000000 +0000
@@ -51,7 +51,7 @@
       # in the FIND_PATH() and FIND_LIBRARY() calls
       INCLUDE(UsePkgConfig)
     
-      PKGCONFIG(libkdcraw _KDCRAWIncDir _KDCRAWLinkDir _KDCRAWLinkFlags _KDCRAWCflags)
+      PKGCONFIG(libkdcraw-kde4 _KDCRAWIncDir _KDCRAWLinkDir _KDCRAWLinkFlags _KDCRAWCflags)
     
       if(_KDCRAWLinkFlags)
         # query pkg-config asking for a libkdcraw >= 0.2.0
