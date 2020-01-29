--- plugins/qmlboxmodel/src/mainwindow.cpp.orig	2018-12-31 15:24:22 UTC
+++ plugins/qmlboxmodel/src/mainwindow.cpp
@@ -397,8 +397,8 @@ bool QmlBoxModel::MainWindow::event(QEvent *event) {
 }
 
 
-#ifdef Q_OS_LINUX
-/** ****************************************************************************
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+/******************************************************************************
  * @brief MainWidget::nativeEvent
  *
  * The purpose of this function is to hide in special casesonly.
