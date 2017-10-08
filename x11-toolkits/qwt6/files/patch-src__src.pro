--- src/src.pro.orig	2016-06-13 07:14:23 UTC
+++ src/src.pro
@@ -17,7 +17,7 @@ include( $${QWT_ROOT}/qwtfunctions.pri )
 QWT_OUT_ROOT = $${OUT_PWD}/..
 
 TEMPLATE          = lib
-TARGET            = $$qwtLibraryTarget(qwt)
+TARGET            = $$qwtLibraryTarget(qwt$${QWT_VER_MAJ})
 
 DESTDIR           = $${QWT_OUT_ROOT}/lib
 
