--- ./designer/designer.pro.orig	2013-05-30 15:18:27.753341000 +0000
+++ ./designer/designer.pro	2013-07-13 21:19:00.492115401 +0000
@@ -42,7 +42,7 @@
 
 
     TEMPLATE        = lib
-    TARGET          = qwt_designer_plugin
+    TARGET          = qwt6_designer_plugin
 
     DESTDIR         = plugins/designer
 
@@ -95,7 +95,7 @@
             LIBS      += -L$${QWT_ROOT}/lib
         }
 
-        qwtAddLibrary(qwt)
+        qwtAddLibrary(qwt6)
 
         contains(QWT_CONFIG, QwtDll) {
 
@@ -124,7 +124,7 @@
 
     RESOURCES += qwt_designer_plugin.qrc
 
-    target.path = $${QWT_INSTALL_PLUGINS}
+    target.path = $$PLUGINDIR/designer
     INSTALLS += target
 }
 else {
