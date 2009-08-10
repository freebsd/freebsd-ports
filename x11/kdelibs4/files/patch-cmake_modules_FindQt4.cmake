--- ./cmake/modules/FindQt4.cmake.orig	2008-10-17 15:01:33.000000000 +0400
+++ ./cmake/modules/FindQt4.cmake	2008-12-16 00:40:06.000000000 +0300
@@ -1096,13 +1096,13 @@
     )
 
   FIND_PROGRAM(QT_LUPDATE_EXECUTABLE
-    NAMES lupdate
+    NAMES lupdate-qt4
     PATHS ${QT_BINARY_DIR}
     NO_DEFAULT_PATH
     )
 
   FIND_PROGRAM(QT_LRELEASE_EXECUTABLE
-    NAMES lrelease
+    NAMES lrelease-qt4
     PATHS ${QT_BINARY_DIR}
     NO_DEFAULT_PATH
     )
