--- src/mainwindow.cpp.orig	2016-11-06 01:23:03 UTC
+++ src/mainwindow.cpp
@@ -364,7 +364,7 @@ void MainWindow::makeJoystickTabs()
         ui->tabWidget->addTab(tabwidget, joytabName);
     }
 
-    if (joysticks > 0)
+    if (joysticks->size() > 0)
     {
         ui->tabWidget->setCurrentIndex(0);
         ui->stackedWidget->setCurrentIndex(1);
