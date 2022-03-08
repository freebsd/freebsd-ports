--- src/src.pro.orig	2021-11-16 21:43:56 UTC
+++ src/src.pro
@@ -7,40 +7,7 @@ QT_FOR_CONFIG += qml qml-private quick-private
 # Otherwise we cannot compile qmltyperegistrar
 requires(qtConfig(commandlineparser))
 
-# We need qmltyperegistrar for all type registrations, even in qml
-SUBDIRS += \
-    qmltyperegistrar \
-    qml \
-    qmlmodels
-
-qtConfig(qml-worker-script): \
-    SUBDIRS += qmlworkerscript
-
-qtHaveModule(gui):qtConfig(qml-animation) {
-    SUBDIRS += quick
-
-    qtConfig(quick-path): \
-        SUBDIRS += quickshapes
-
-    qtConfig(testlib): \
-        SUBDIRS += qmltest
-
-    qtConfig(quick-particles): \
-        SUBDIRS += particles
-    qtHaveModule(widgets): SUBDIRS += quickwidgets
-}
-
-SUBDIRS += \
-    plugins \
-    imports
-
-qtConfig(qml-devtools): SUBDIRS += qmldevtools
-
-qmldevtools.depends = qml
-
-qtConfig(qml-network) {
-    QT_FOR_CONFIG += network
-    qtConfig(thread):qtConfig(localserver):qtConfig(qml-debug): SUBDIRS += qmldebug
-}
+SUBDIRS += qmltest \
+           imports
 
 DISTFILES += sync.profile configure.json
