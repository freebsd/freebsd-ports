- disable the depracated QWebKit dependency

--- extensions/PythonQt_QtAll/PythonQt_QtAll.pro.orig	2026-09-15 16:14:25 UTC
+++ extensions/PythonQt_QtAll/PythonQt_QtAll.pro
@@ -23,7 +23,7 @@ isEmpty( PYTHONQTALL_CONFIG ) {
   qtHaveModule(uitools):CONFIG += PythonQtUiTools
   qtHaveModule(webenginewidgets):CONFIG += PythonQtWebEngineWidgets
 
-  qtHaveModule(webkit):CONFIG += PythonQtWebKit
+  #qtHaveModule(webkit):CONFIG += PythonQtWebKit
 } else {
   message("using given PythonQt_QtAll Configuration: ")
   message("  $${PYTHONQTALL_CONFIG}")
