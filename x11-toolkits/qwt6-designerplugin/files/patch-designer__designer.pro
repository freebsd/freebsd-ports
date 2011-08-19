--- ./designer/designer.pro.orig	2011-08-01 14:33:53.000000000 +0000
+++ ./designer/designer.pro	2011-08-19 15:46:20.185856767 +0000
@@ -18,7 +18,7 @@
     CONFIG    += warn_on
 
     TEMPLATE        = lib
-    TARGET          = qwt_designer_plugin
+    TARGET          = qwt6_designer_plugin
 
     DESTDIR         = plugins/designer
 
@@ -35,7 +35,7 @@
     }
 
     IPATH       = $${INCLUDEPATH}
-    qtAddLibrary(qwt)
+    qtAddLibrary(qwt6)
     INCLUDEPATH = $${IPATH}
 
     contains(QWT_CONFIG, QwtDll) {
@@ -64,7 +64,7 @@
 
     RESOURCES += qwt_designer_plugin.qrc
 
-    target.path = $${QWT_INSTALL_PLUGINS}
+    target.path = $$PLUGINDIR/designer
     INSTALLS += target
 }
 else {
