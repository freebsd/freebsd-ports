--- ../plasma/applets/systemtray/systemtraywidget.cpp	2008/07/03 02:32:22	827463
+++ ../plasma/applets/systemtray/systemtraywidget.cpp	2008/08/05 13:57:28	842541
@@ -52,6 +52,17 @@
     // Override spacing set by the current style
     m_mainLayout->setContentsMargins(0, 0, 0, 0);
     m_mainLayout->setSpacing(4);
+
+    // Widgets added to the parent before this one may end up
+    // on top of this one if their native windows are created
+    // after this one, so raise() to make sure this widget is
+    // on top.
+    // raise() -- doesn't work for some reason
+    foreach (QObject *sibling, parent->children()) {
+        if (sibling != this && sibling->isWidgetType()) {
+            static_cast<QWidget*>(sibling)->lower();
+        }
+    }
 }
 
 void SystemTrayWidget::init()
