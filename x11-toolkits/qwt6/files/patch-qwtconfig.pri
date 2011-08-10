--- qwtconfig.pri.orig	2011-08-08 08:09:26.000000000 +0000
+++ qwtconfig.pri	2011-08-08 08:11:17.000000000 +0000
@@ -8,7 +8,7 @@
 VERSION      = $${VER_MAJ}.$${VER_MIN}.$${VER_PAT}
 
 unix {
-    INSTALLBASE    = /usr/local/qwt-$$VERSION
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
@@ -98,7 +97,7 @@
 # QwtSVGItem.
 ######################################################################
 
-#CONFIG     += QwtSVGItem
+CONFIG     += QwtSVGItem
 
 ######################################################################
 # You can use the MathML renderer of the Qt solutions package to 
@@ -115,7 +114,7 @@
 # Otherwise you have to build it from the designer directory.
 ######################################################################
 
-CONFIG     += QwtDesigner
+#CONFIG     += QwtDesigner
 
 ######################################################################
 # If you want to auto build the examples, enable the line below
