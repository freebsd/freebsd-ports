--- ./src/src.pro.orig	2012-11-30 13:22:47.000000000 +0000
+++ ./src/src.pro	2012-12-13 12:53:01.312756345 +0000
@@ -15,7 +15,7 @@
 include( $${QWT_ROOT}/qwtfunctions.pri )
 
 TEMPLATE          = lib
-TARGET            = $$qwtLibraryTarget(qwt)
+TARGET            = $$qwtLibraryTarget(qwt$${QWT_VER_MAJ})
 
 DESTDIR           = $${QWT_ROOT}/lib
 
@@ -221,7 +221,7 @@
 unix:doc.files += $${QWT_ROOT}/doc/man
 doc.path       = $${QWT_INSTALL_DOCS}
 
-INSTALLS       = target doc
+INSTALLS       = target
 
 CONFIG(lib_bundle) {
 
