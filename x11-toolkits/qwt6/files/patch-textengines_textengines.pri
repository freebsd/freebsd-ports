--- textengines/textengines.pri.orig	2017-10-06 14:51:21 UTC
+++ textengines/textengines.pri
@@ -34,7 +34,7 @@ contains(QWT_CONFIG, QwtFramework) {
     CONFIG += lib_bundle
 }
 
-qwtAddLibrary($${QWT_OUT_ROOT}/lib, qwt)
+qwtAddLibrary($${QWT_OUT_ROOT}/lib, qwt6)
 
 # Install directives
 
