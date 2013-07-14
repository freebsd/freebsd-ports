--- ./qwtconfig.pri.orig	2013-05-30 15:18:27.767341000 +0000
+++ ./qwtconfig.pri	2013-07-13 21:02:00.112110333 +0000
@@ -19,7 +19,7 @@
 QWT_INSTALL_PREFIX = $$[QT_INSTALL_PREFIX]
 
 unix {
-    QWT_INSTALL_PREFIX    = /usr/local/qwt-$$QWT_VERSION
+    QWT_INSTALL_PREFIX    = $$PREFIX
 }
 
 win32 {
@@ -27,7 +27,7 @@
 }
 
 QWT_INSTALL_DOCS      = $${QWT_INSTALL_PREFIX}/doc
-QWT_INSTALL_HEADERS   = $${QWT_INSTALL_PREFIX}/include
+QWT_INSTALL_HEADERS   = $${QWT_INSTALL_PREFIX}/include/qwt6/
 QWT_INSTALL_LIBS      = $${QWT_INSTALL_PREFIX}/lib
 
 ######################################################################
@@ -61,7 +61,7 @@
 # with every Qt upgrade. 
 ######################################################################
 
-QWT_INSTALL_FEATURES  = $${QWT_INSTALL_PREFIX}/features
+QWT_INSTALL_FEATURES  = $${QWT_INSTALL_PREFIX}/share/qt4/mkspecs/features
 # QWT_INSTALL_FEATURES  = $$[QT_INSTALL_PREFIX]/features
 
 ######################################################################
@@ -108,7 +108,7 @@
 # to your qmake project file.
 ######################################################################
 
-#QWT_CONFIG     += QwtMathML
+QWT_CONFIG     += QwtMathML
 
 ######################################################################
 # If you want to build the Qwt designer plugin, 
@@ -116,7 +116,7 @@
 # Otherwise you have to build it from the designer directory.
 ######################################################################
 
-QWT_CONFIG     += QwtDesigner
+# QWT_CONFIG     += QwtDesigner
 
 ######################################################################
 # Compile all Qwt classes into the designer plugin instead
