Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/designer/src/src.pro.orig	2016-01-21 10:39:28 UTC
+++ src/designer/src/src.pro
@@ -1,28 +1,4 @@
 TEMPLATE = subdirs
 
 SUBDIRS = \
-    uiplugin \
-    uitools
-
-qtConfig(process) {
-    SUBDIRS += \
-        lib \
-        components \
-        designer
-
-    lib.depends = uiplugin
-    components.depends = lib
-    designer.depends = components
-    plugins.depends = lib
-
-    contains(QT_CONFIG, shared): SUBDIRS += plugins
-}
-
-uitools.depends = uiplugin
-
-qtNomakeTools( \
-    lib \
-    components \
-    designer \
-    plugins \
-)
+    uiplugin
