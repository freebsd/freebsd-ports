Fix the pkgconfig install path.

--- src/charts/charts.pro.orig	2016-12-01 12:57:55 UTC
+++ src/charts/charts.pro
@@ -17,6 +17,9 @@ load(qt_module)
 QMAKE_TARGET_PRODUCT = "Qt Charts (Qt $$QT_VERSION)"
 QMAKE_TARGET_DESCRIPTION = "Charts component for Qt."
 
+# Properly set up the pkgconfig install path -- relative to lib/ 
+QMAKE_PKGCONFIG_DESTDIR = ../libdata/pkgconfig
+
 ############################# SOURCES ##########################################
 
 SOURCES += \
