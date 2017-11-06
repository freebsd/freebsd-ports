--- qwtconfig.pri.orig	2016-06-13 07:14:23 UTC
+++ qwtconfig.pri
@@ -19,7 +19,7 @@ QWT_VERSION      = $${QWT_VER_MAJ}.$${QW
 QWT_INSTALL_PREFIX = $$[QT_INSTALL_PREFIX]
 
 unix {
-    QWT_INSTALL_PREFIX    = /usr/local/qwt-$$QWT_VERSION
+    QWT_INSTALL_PREFIX    = $$PREFIX
     # QWT_INSTALL_PREFIX = /usr/local/qwt-$$QWT_VERSION-qt-$$QT_VERSION
 }
 
@@ -29,7 +29,7 @@ win32 {
 }
 
 QWT_INSTALL_DOCS      = $${QWT_INSTALL_PREFIX}/doc
-QWT_INSTALL_HEADERS   = $${QWT_INSTALL_PREFIX}/include
+QWT_INSTALL_HEADERS   = $${QWT_INSTALL_PREFIX}/include/qwt6
 QWT_INSTALL_LIBS      = $${QWT_INSTALL_PREFIX}/lib
 
 ######################################################################
@@ -63,7 +63,7 @@ QWT_INSTALL_PLUGINS   = $${QWT_INSTALL_P
 # with every Qt upgrade. 
 ######################################################################
 
-QWT_INSTALL_FEATURES  = $${QWT_INSTALL_PREFIX}/features
+QWT_INSTALL_FEATURES  = $${QWT_INSTALL_PREFIX}/share/qt4/mkspecs/features
 # QWT_INSTALL_FEATURES  = $$[QT_INSTALL_PREFIX]/features
 
 ######################################################################
@@ -110,7 +110,7 @@ QWT_CONFIG     += QwtOpenGL
 # to your qmake project file.
 ######################################################################
 
-#QWT_CONFIG     += QwtMathML
+QWT_CONFIG     += QwtMathML
 
 ######################################################################
 # If you want to build the Qwt designer plugin, 
@@ -118,7 +118,7 @@ QWT_CONFIG     += QwtOpenGL
 # Otherwise you have to build it from the designer directory.
 ######################################################################
 
-QWT_CONFIG     += QwtDesigner
+#QWT_CONFIG     += QwtDesigner
 
 ######################################################################
 # Compile all Qwt classes into the designer plugin instead
