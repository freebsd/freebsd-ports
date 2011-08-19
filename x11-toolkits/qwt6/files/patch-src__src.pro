--- ./src/src.pro.orig	2011-08-01 14:33:53.000000000 +0000
+++ ./src/src.pro	2011-08-19 09:33:07.161341857 +0000
@@ -14,7 +14,7 @@
 include( $${QWT_ROOT}/qwtbuild.pri )
 
 TEMPLATE          = lib
-TARGET            = $$qtLibraryTarget(qwt)
+TARGET            = $$qtLibraryTarget(qwt$${QWT_VER_MAJ})
 
 DESTDIR           = $${QWT_ROOT}/lib
 
@@ -220,7 +220,7 @@
 unix:doc.files += $${QWT_ROOT}/doc/man
 doc.path       = $${QWT_INSTALL_DOCS}
 
-INSTALLS       = target doc
+INSTALLS       = target
 
 CONFIG(lib_bundle) {
 
