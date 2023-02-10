--- PythonQt.pro.orig	2023-02-01 08:09:21 UTC
+++ PythonQt.pro
@@ -1,6 +1,6 @@
 TEMPLATE = subdirs
 
-SUBDIRS = generator src extensions tests examples
+SUBDIRS = generator src extensions #tests examples
 tests.depends += src extensions
 extensions.depends += src
 examples.depends += src extensions
