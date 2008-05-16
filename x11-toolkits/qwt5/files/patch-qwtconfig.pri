--- ./qwtconfig.pri.orig	2008-05-01 17:43:56.000000000 +0400
+++ ./qwtconfig.pri	2008-05-03 02:21:17.000000000 +0400
@@ -8,7 +8,7 @@
 VERSION      = $$VER_MAJ.$$VER_MIN.$$VER_PAT
 
 unix {
-    INSTALLBASE    = /usr/local/qwt-5.1.0
+    INSTALLBASE    = $$PREFIX
 }
 
 win32 {
@@ -16,8 +16,7 @@
 }
 
 target.path    = $$INSTALLBASE/lib
-headers.path   = $$INSTALLBASE/include
-doc.path       = $$INSTALLBASE/doc
+headers.path   = $$INSTALLBASE/include/qwt
 
 ######################################################################
 # qmake internal options
@@ -97,7 +96,7 @@
 # QwtSVGItem.
 ######################################################################
 
-#CONFIG     += QwtSVGItem
+CONFIG     += QwtSVGItem
 
 ######################################################################
 # If you have a commercial license you can use the MathML renderer
@@ -114,7 +113,7 @@
 # Otherwise you have to build it from the designer directory.
 ######################################################################
 
-CONFIG     += QwtDesigner
+#CONFIG     += QwtDesigner
 
 ######################################################################
 # If you want to auto build the examples, enable the line below
