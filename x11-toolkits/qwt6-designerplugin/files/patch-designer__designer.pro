--- ./designer/designer.pro.orig	2012-11-30 13:22:47.000000000 +0000
+++ ./designer/designer.pro	2012-12-13 12:55:56.229759237 +0000
@@ -19,7 +19,7 @@
     CONFIG    += warn_on
 
     TEMPLATE        = lib
-    TARGET          = qwt_designer_plugin
+    TARGET          = qwt6_designer_plugin
 
     DESTDIR         = plugins/designer
 
@@ -35,7 +35,7 @@
         LIBS      += -L$${QWT_ROOT}/lib
     }
 
-    qwtAddLibrary(qwt)
+    qwtAddLibrary(qwt6)
 
     contains(QWT_CONFIG, QwtDll) {
 
@@ -63,7 +63,7 @@
 
     RESOURCES += qwt_designer_plugin.qrc
 
-    target.path = $${QWT_INSTALL_PLUGINS}
+    target.path = $$PLUGINDIR/designer
     INSTALLS += target
 }
 else {
