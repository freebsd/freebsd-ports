--- ./src/src.pro.orig	2013-05-30 15:18:27.693341000 +0000
+++ ./src/src.pro	2013-07-13 20:54:02.367114849 +0000
@@ -15,7 +15,7 @@
 include( $${QWT_ROOT}/qwtfunctions.pri )
 
 TEMPLATE          = lib
-TARGET            = $$qwtLibraryTarget(qwt)
+TARGET            = $$qwtLibraryTarget(qwt$${QWT_VER_MAJ})
 
 DESTDIR           = $${QWT_ROOT}/lib
 
