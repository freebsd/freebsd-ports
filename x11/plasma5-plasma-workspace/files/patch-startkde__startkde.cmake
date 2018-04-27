--- startkde/startkde.cmake.orig	2017-01-12 17:46:38 UTC
+++ startkde/startkde.cmake
@@ -2,6 +2,22 @@
 #
 #  DEFAULT KDE STARTUP SCRIPT ( @PROJECT_VERSION@ )
 #
+# FreeBSD: add ${QTPREFIX}/lib/qt5/bin to path - note, this should be done better
+PATH=${PATH}:%%QT_BINDIR%%
+export PATH
+
+# FreeBSD: add xdg-dirs (see misc/kde4-xdg-env)
+XDG_CONFIG_DIRS=${XDG_CONFIG_DIRS}:/etc/xdg:%%LOCALBASE%%/etc/xdg:%%LOCALBASE%%/etc/xdg/xfce:%%KDE_PREFIX%%/etc/xdg
+export XDG_CONFIG_DIRS
+
+XDG_DATA_DIRS=${XDG_DATA_DIRS}:/usr/share:%%KDE_PREFIX%%/share:%%LOCALBASE%%/share:%%LOCALBASE%%/share/gnome
+export XDG_DATA_DIRS
+
+# FreeBSD: add qml/qt-plugin paths
+QML2_IMPORT_PATH="%%KDE_PREFIX%%/lib/qml:%%QT_QMLDIR%%:%%QT_IMPORTDIR%%:${QML2_IMPORT_PATH}"
+export QML2_IMPORT_PATH
+QT_PLUGIN_PATH="%%KDE_PREFIX%%/lib/plugins:%%QT_PLUGINDIR%%:${QT_PLUGIN_PATH}"
+export QT_PLUGIN_PATH
 
 # When the X server dies we get a HUP signal from xinit. We must ignore it
 # because we still need to do some cleanup.
