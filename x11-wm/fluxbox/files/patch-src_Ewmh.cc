--- src/Ewmh.cc.orig	2018-02-17 12:06:58 UTC
+++ src/Ewmh.cc
@@ -914,7 +914,7 @@ void Ewmh::updateGeometry(BScreen &screen) {
      * Window Manager.
      *
      */
-    long value[2] = {screen.width(), screen.height()};
+    long value[2] = {static_cast<long>(screen.width()), static_cast<long>(screen.height())};
     screen.rootWindow().changeProperty(m_net->desktop_geometry,
                                        XA_CARDINAL, 32,
                                        PropModeReplace,
