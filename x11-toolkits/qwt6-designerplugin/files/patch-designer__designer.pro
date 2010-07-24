--- ./designer/designer.pro.orig	2008-05-01 17:43:56.000000000 +0400
+++ ./designer/designer.pro	2008-05-03 02:21:17.000000000 +0400
@@ -123,7 +123,7 @@
         RESOURCES += \
             qwt_designer_plugin.qrc
 
-        target.path = $$[QT_INSTALL_PLUGINS]/designer
+        target.path = $$PLUGINDIR/designer
         INSTALLS += target
     }
 }
