--- tools/tools.pro.orig	2021-09-24 07:53:27 UTC
+++ tools/tools.pro
@@ -37,8 +37,6 @@ qtConfig(thread):!android|android_app:!wasm:!rtems {
             }
         }
     }
-    qtHaveModule(qmltest): SUBDIRS += qmltestrunner
-    qtConfig(private_tests): SUBDIRS += qmljs
 }
 
 qtConfig(qml-devtools) {
