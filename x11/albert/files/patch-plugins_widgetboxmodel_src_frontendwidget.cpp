--- plugins/widgetboxmodel/src/frontendwidget.cpp.orig	2018-12-31 15:24:22 UTC
+++ plugins/widgetboxmodel/src/frontendwidget.cpp
@@ -656,7 +656,7 @@ bool WidgetBoxModel::FrontendWidget::eventFilter(QObje
 }
 
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) 
 /** ****************************************************************************
  * @brief MainWidget::nativeEvent
  *
