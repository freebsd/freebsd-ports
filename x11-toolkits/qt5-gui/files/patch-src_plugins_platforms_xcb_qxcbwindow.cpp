--- src/plugins/platforms/xcb/qxcbwindow.cpp.orig	2015-01-29 15:05:03.094563565 -0500
+++ src/plugins/platforms/xcb/qxcbwindow.cpp	2015-01-29 15:08:10.219554046 -0500
@@ -701,6 +701,9 @@
     if (connection()->time() != XCB_TIME_CURRENT_TIME)
         updateNetWmUserTime(connection()->time());
 
+    if (window()->objectName() == QLatin1String("QSystemTrayIconSysWindow"))
+	return; // defer showing until XEMBED_EMBEDDED_NOTIFY
+
     Q_XCB_CALL(xcb_map_window(xcb_connection(), m_window));
 
     if (QGuiApplication::modalWindow() == window())
@@ -2130,7 +2133,10 @@
     switch (event->data.data32[1]) {
     case XEMBED_WINDOW_ACTIVATE:
     case XEMBED_WINDOW_DEACTIVATE:
+	break;
     case XEMBED_EMBEDDED_NOTIFY:
+	Q_XCB_CALL(xcb_map_window(xcb_connection(), m_window));
+	m_screen->windowShown(this);
         break;
     case XEMBED_FOCUS_IN:
         Qt::FocusReason reason;
