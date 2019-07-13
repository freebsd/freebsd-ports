--- src/qgtkintegration.cpp.orig	2019-07-13 09:12:31 UTC
+++ src/qgtkintegration.cpp
@@ -131,7 +131,11 @@ void QGtkIntegration::onMonitorAdded(GdkMonitor *monit
 {
     qDebug() << "Added " << monitor;
     m_screens.append(new QGtkScreen(monitor));
-    screenAdded(m_screens.at(m_screens.count() - 1));
+    #if (QT_VERSION >= QT_VERSION_CHECK(5, 13, 0))
+        QWindowSystemInterface::handleScreenAdded(m_screens.at(m_screens.count() - 1));
+    #else
+        screenAdded(m_screens.at(m_screens.count() - 1));
+    #endif
 }
 
 void QGtkIntegration::onMonitorRemoved(GdkMonitor *monitor)
@@ -139,7 +143,11 @@ void QGtkIntegration::onMonitorRemoved(GdkMonitor *mon
     qDebug() << "Removed " << monitor;
     for (int i = 0; i < m_screens.count(); ++i) {
         if (m_screens.at(i)->monitor() == monitor) {
-            removeScreen(m_screens.at(i)->screen());
+            #if (QT_VERSION >= QT_VERSION_CHECK(5, 13, 0))
+                QWindowSystemInterface::handleScreenRemoved(m_screens.at(i));
+            #else
+                removeScreen(m_screens.at(i)->screen());
+            #endif
             m_screens.removeAt(i);
             return;
         }
