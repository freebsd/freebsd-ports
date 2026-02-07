--- plugins/widgetsboxmodel/src/window.cpp.orig	2025-07-13 17:56:08 UTC
+++ plugins/widgetsboxmodel/src/window.cpp
@@ -1089,9 +1089,11 @@ bool Window::event(QEvent *event)
 
     else if (event->type() == QEvent::ThemeChange)
     {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         // No automatic palette update on GNOME
         QApplication::setPalette(QApplication::style()->standardPalette());
+#else
+#   error "Unknown architecture"
 #endif
         dark_mode = haveDarkSystemPalette();
         applyTheme((dark_mode) ? theme_dark_ : theme_light_);
