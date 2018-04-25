--- designer/designer.pro.orig	2018-03-06 14:52:45 UTC
+++ designer/designer.pro
@@ -42,7 +42,7 @@ contains(QWT_CONFIG, QwtDesigner) {
 
 
     TEMPLATE        = lib
-    TARGET          = qwt_designer_plugin
+    TARGET          = qwt6_designer_plugin
 
     DESTDIR         = plugins/designer
 
@@ -84,7 +84,7 @@ contains(QWT_CONFIG, QwtDesigner) {
         # into the plugin. Not supported on Windows !
 
         QMAKE_RPATHDIR *= $${QWT_INSTALL_LIBS}
-        qwtAddLibrary($${QWT_OUT_ROOT}/lib, qwt)
+        qwtAddLibrary($${QWT_OUT_ROOT}/lib, qwt6)
 
         contains(QWT_CONFIG, QwtDll) {
 
@@ -113,7 +113,7 @@ contains(QWT_CONFIG, QwtDesigner) {
 
     RESOURCES += qwt_designer_plugin.qrc
 
-    target.path = $${QWT_INSTALL_PLUGINS}
+    target.path = $$PLUGINDIR/designer
     INSTALLS += target
 }
 else {
