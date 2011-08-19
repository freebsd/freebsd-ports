--- ./qwtconfig.pri.orig	2011-08-01 14:33:53.000000000 +0000
+++ ./qwtconfig.pri	2011-08-19 09:57:08.979331152 +0000
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
@@ -49,7 +49,7 @@
 # with every Qt upgrade. 
 ######################################################################
 
-QWT_INSTALL_FEATURES  = $${QWT_INSTALL_PREFIX}/features
+QWT_INSTALL_FEATURES  = $${QWT_INSTALL_PREFIX}/share/qt4/mkspecs/features
 # QWT_INSTALL_FEATURES  = $${QT_INSTALL_PREFIX}/features
 
 ######################################################################
@@ -98,7 +98,7 @@
 # Otherwise you have to build it from the designer directory.
 ######################################################################
 
-QWT_CONFIG     += QwtDesigner
+# QWT_CONFIG     += QwtDesigner
 
 ######################################################################
 # If you want to auto build the examples, enable the line below
