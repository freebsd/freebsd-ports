--- ../cmake/modules/FindQCA2.cmake.orig	2008-07-11 14:15:58.000000000 +0200
+++ ../cmake/modules/FindQCA2.cmake	2008-07-11 14:16:35.000000000 +0200
@@ -26,7 +26,7 @@
   INCLUDE(UsePkgConfig)
 
   IF (NOT WIN32)
-    PKGCONFIG(qca2 QCA2_INCLUDE_DIR _Qca2LinkDir _Qca2LinkFlags _Qca2Cflags)
+    PKGCONFIG(qca QCA2_INCLUDE_DIR _Qca2LinkDir _Qca2LinkFlags _Qca2Cflags)
 
     set(QCA2_DEFINITIONS ${_Qca2Cflags})
 
