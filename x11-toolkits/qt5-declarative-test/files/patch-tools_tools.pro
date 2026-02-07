--- tools/tools.pro.orig	2021-09-24 07:43:40 UTC
+++ tools/tools.pro
@@ -1,45 +1,8 @@
 TEMPLATE = subdirs
 QT_FOR_CONFIG += qml-private
 
-qtConfig(qml-devtools) {
-    SUBDIRS += \
-        qmllint \
-        qmlmin \
-        qmlimportscanner \
-        qmlformat
-
-    qtConfig(commandlineparser):qtConfig(xmlstreamwriter): SUBDIRS += qmlcachegen
-}
-
-qtConfig(thread):!android|android_app:!wasm:!rtems {
-    SUBDIRS += \
-        qml
-
-    qtConfig(qml-profiler): SUBDIRS += qmlprofiler
-    qtConfig(qml-preview): SUBDIRS += qmlpreview
-
-    qtHaveModule(quick) {
-        !static: {
-            SUBDIRS += \
-                qmlscene \
-                qmltime
-
-            qtConfig(regularexpression):qtConfig(process) {
-                SUBDIRS += \
-                    qmlplugindump
-            }
-        }
-        qtHaveModule(widgets) {
-            QT_FOR_CONFIG += widgets
-            qtConfig(dialogbuttonbox) {
-                SUBDIRS += \
-                    qmleasing
-            }
-        }
-    }
-    qtHaveModule(qmltest): SUBDIRS += qmltestrunner
-    qtConfig(private_tests): SUBDIRS += qmljs
-}
+SUBDIRS += qmltestrunner
+qtConfig(private_tests): SUBDIRS += qmljs
 
 qtConfig(qml-devtools) {
     qml.depends = qmlimportscanner
