--- src/src.pro.orig	2021-09-24 07:16:45 UTC
+++ src/src.pro
@@ -22,9 +22,6 @@ qtHaveModule(gui):qtConfig(qml-animation) {
     qtConfig(quick-path): \
         SUBDIRS += quickshapes
 
-    qtConfig(testlib): \
-        SUBDIRS += qmltest
-
     qtConfig(quick-particles): \
         SUBDIRS += particles
     qtHaveModule(widgets): SUBDIRS += quickwidgets
