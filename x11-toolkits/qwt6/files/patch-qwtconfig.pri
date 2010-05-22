--- ./qwtconfig.pri.orig	2009-03-22 18:41:05.000000000 +0300
+++ ./qwtconfig.pri	2009-03-25 23:02:54.000000000 +0300
@@ -8,7 +8,7 @@
 VERSION      = $${VER_MAJ}.$${VER_MIN}.$${VER_PAT}
 
 unix {
-    INSTALLBASE    = /usr/local/qwt-5.2.1
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
