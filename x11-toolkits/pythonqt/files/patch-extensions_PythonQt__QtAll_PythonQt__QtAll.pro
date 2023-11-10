- disable the depracated QWebKit dependency

--- extensions/PythonQt_QtAll/PythonQt_QtAll.pro.orig	2023-11-02 20:40:29 UTC
+++ extensions/PythonQt_QtAll/PythonQt_QtAll.pro
@@ -19,7 +19,7 @@ isEmpty( PYTHONQTALL_CONFIG ) {
   qtHaveModule(quick):CONFIG += PythonQtQuick
   qtHaveModule(uitools):CONFIG += PythonQtUiTools
 
-  qtHaveModule(webkit):CONFIG += PythonQtWebKit
+  #qtHaveModule(webkit):CONFIG += PythonQtWebKit
 } else {
   message("using given PythonQt_QtAll Configuration: ")
   message("  $${PYTHONQTALL_CONFIG}")
