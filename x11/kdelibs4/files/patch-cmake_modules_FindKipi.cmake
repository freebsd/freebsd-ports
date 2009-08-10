--- ./cmake/modules/FindKipi.cmake.orig	2009-01-06 17:27:37.000000000 +0000
+++ ./cmake/modules/FindKipi.cmake	2009-01-25 08:35:05.000000000 +0000
@@ -50,7 +50,7 @@
       # in the FIND_PATH() and FIND_LIBRARY() calls
       INCLUDE(UsePkgConfig)
 
-      PKGCONFIG(libkipi _KIPIIncDir _KIPILinkDir _KIPILinkFlags _KIPICflags)
+      PKGCONFIG(libkipi-kde4 _KIPIIncDir _KIPILinkDir _KIPILinkFlags _KIPICflags)
 
       if(_KIPILinkFlags)
         # query pkg-config asking for a libkipi >= 0.2.0
