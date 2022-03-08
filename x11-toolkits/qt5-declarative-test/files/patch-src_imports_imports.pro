--- src/imports/imports.pro.orig	2022-03-08 11:32:59 UTC
+++ src/imports/imports.pro
@@ -1,34 +1,4 @@
 TEMPLATE = subdirs
 QT_FOR_CONFIG += qml-private
 
-SUBDIRS += \
-    builtins \
-    qtqml \
-    models \
-    labsmodels
-
-qtConfig(qml-itemmodel): SUBDIRS += folderlistmodel
-qtConfig(qml-worker-script): SUBDIRS += workerscript
-qtHaveModule(sql): SUBDIRS += localstorage
-qtConfig(settings): SUBDIRS += settings
-qtConfig(statemachine): SUBDIRS += statemachine
-
-qtHaveModule(quick) {
-    QT_FOR_CONFIG += quick-private
-
-    SUBDIRS += \
-        labsanimation \
-        layouts \
-        qtquick2 \
-        window
-
-    qtConfig(quick-shadereffect): SUBDIRS += wavefrontmesh
-
-    qtHaveModule(testlib): SUBDIRS += testlib
-    qtConfig(systemsemaphore): SUBDIRS += sharedimage
-    qtConfig(quick-particles): \
-        SUBDIRS += particles
-
-    qtConfig(quick-path): SUBDIRS += shapes
-}
-
+SUBDIRS=	testlib
