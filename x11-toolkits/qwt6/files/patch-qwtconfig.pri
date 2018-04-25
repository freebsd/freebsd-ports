--- qwtconfig.pri.orig	2018-03-06 14:23:36 UTC
+++ qwtconfig.pri
@@ -19,7 +19,7 @@ QWT_VERSION      = $${QWT_VER_MAJ}.$${QW
 QWT_INSTALL_PREFIX = $$[QT_INSTALL_PREFIX]
 
 unix {
-    QWT_INSTALL_PREFIX    = /usr/local/qwt-$$QWT_VERSION
+    QWT_INSTALL_PREFIX    = $$PREFIX
     # QWT_INSTALL_PREFIX = /usr/local/qwt-$$QWT_VERSION-qt-$$QT_VERSION
 }
 
@@ -28,9 +28,9 @@ win32 {
     # QWT_INSTALL_PREFIX = C:/Qwt-$$QWT_VERSION-qt-$$QT_VERSION
 }
 
-QWT_INSTALL_DOCS      = $${QWT_INSTALL_PREFIX}/doc
-QWT_INSTALL_HEADERS   = $${QWT_INSTALL_PREFIX}/include
-QWT_INSTALL_LIBS      = $${QWT_INSTALL_PREFIX}/lib
+QWT_INSTALL_DOCS      = $${QWT_INSTALL_PREFIX}/share/doc/qwt6-qt%%QT_VERSION%%
+QWT_INSTALL_HEADERS   = %%QT_INCDIR%%/qwt6
+QWT_INSTALL_LIBS      = %%QT_LIBDIR%%
 
 ######################################################################
 # Designer plugin
@@ -42,7 +42,7 @@ QWT_INSTALL_LIBS      = $${QWT_INSTALL_P
 # runtime environment of designer/creator.
 ######################################################################
 
-QWT_INSTALL_PLUGINS   = $${QWT_INSTALL_PREFIX}/plugins/designer
+QWT_INSTALL_PLUGINS   = %%QT_LIBDIR%%/plugins/designer
 
 # linux distributors often organize the Qt installation
 # their way and QT_INSTALL_PREFIX doesn't offer a good
@@ -63,7 +63,7 @@ QWT_INSTALL_PLUGINS   = $${QWT_INSTALL_P
 # with every Qt upgrade. 
 ######################################################################
 
-QWT_INSTALL_FEATURES  = $${QWT_INSTALL_PREFIX}/features
+QWT_INSTALL_FEATURES  = %%QT_MKSPECDIR%%/features
 # QWT_INSTALL_FEATURES  = $$[QT_INSTALL_PREFIX]/features
 
 ######################################################################
@@ -110,7 +110,7 @@ QWT_CONFIG     += QwtOpenGL
 # to your qmake project file.
 ######################################################################
 
-#QWT_CONFIG     += QwtMathML
+QWT_CONFIG     += QwtMathML
 
 ######################################################################
 # If you want to build the Qwt designer plugin, 
