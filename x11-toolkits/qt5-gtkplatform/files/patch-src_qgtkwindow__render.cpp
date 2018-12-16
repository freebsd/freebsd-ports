Fix build against Qt5-5.12.0

--- src/qgtkwindow_render.cpp.orig	2017-12-18 21:17:27 UTC
+++ src/qgtkwindow_render.cpp
@@ -121,7 +121,9 @@ void QGtkWindow::onWindowTickCallback()
     if (m_wantsUpdate) {
         m_wantsUpdate = false;
         TRACE_EVENT_ASYNC_END0("gfx", "QGtkWindow::requestUpdate", this);
-        QWindowPrivate::get(window())->deliverUpdateRequest();
+
+        QPlatformWindow *platformWindow = window()->handle();
+        platformWindow->deliverUpdateRequest();
     }
 }
 
