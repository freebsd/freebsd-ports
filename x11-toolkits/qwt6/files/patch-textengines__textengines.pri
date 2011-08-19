--- ./textengines/textengines.pri.orig	2011-08-01 14:33:53.000000000 +0000
+++ ./textengines/textengines.pri	2011-08-19 09:34:56.246332690 +0000
@@ -37,7 +37,7 @@
 }
 
 IPATH       = $${INCLUDEPATH}
-qtAddLibrary(qwt)
+qtAddLibrary(qwt6)
 INCLUDEPATH = $${IPATH}
 
 # Install directives
