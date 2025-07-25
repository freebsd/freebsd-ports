Fix the crash that happens when right-clicking the desktop surface

--- src/qwaylandlayersurface.cpp.orig	2025-07-15 09:53:41 UTC
+++ src/qwaylandlayersurface.cpp
@@ -113,10 +113,8 @@ void QWaylandLayerSurface::attachPopup(QtWaylandClient
 
 void QWaylandLayerSurface::attachPopup(QtWaylandClient::QWaylandShellSurface *popup)
 {
-    std::any anyRole = popup->surfaceRole();
-
-    if (auto role = std::any_cast<::xdg_popup *>(&anyRole)) {
-        get_popup(*role);
+    if (auto role = popup->nativeResource("xdg_popup")) {
+        get_popup(reinterpret_cast<struct ::xdg_popup*>(role));
     } else {
         qCWarning(LAYERSHELLQT) << "Cannot attach popup of unknown type";
     }
