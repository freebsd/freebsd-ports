--- designer/designer.pro.orig	2022-03-09 06:02:25 UTC
+++ designer/designer.pro
@@ -122,7 +122,7 @@ contains(QWT_CONFIG, QwtDesigner) {
     SOURCES += qwt_designer_plugin.cpp
     RESOURCES += qwt_designer_plugin.qrc
 
-    target.path = $${QWT_INSTALL_PLUGINS}
+    target.path = $$PLUGINDIR/designer
     INSTALLS += target
 }
 else {
