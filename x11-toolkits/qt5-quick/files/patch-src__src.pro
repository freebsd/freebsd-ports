Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/src.pro
+++ src/src.pro
@@ -1,7 +1,5 @@
 TEMPLATE = subdirs
 CONFIG += ordered
-SUBDIRS += \
-    qml
 
 qtHaveModule(gui):contains(QT_CONFIG, opengl(es1|es2)?) {
     SUBDIRS += \
@@ -14,7 +12,4 @@ qtHaveModule(gui):contains(QT_CONFIG, opengl(es1|es2)?) {
 
 SUBDIRS += \
     plugins \
-    imports \
-    qmldevtools
-
-qmldevtools.CONFIG = host_build
+    imports
