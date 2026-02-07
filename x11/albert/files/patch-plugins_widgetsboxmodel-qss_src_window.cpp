--- plugins/widgetsboxmodel-qss/src/window.cpp.orig	2025-07-13 18:02:04 UTC
+++ plugins/widgetsboxmodel-qss/src/window.cpp
@@ -729,8 +729,9 @@ bool Window::event(QEvent *event)
         if (auto have_dark_system_palette = haveDarkSystemPalette();
             dark_mode_ != have_dark_system_palette)
         {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
             QApplication::setPalette(QApplication::style()->standardPalette());
+#   else "Unknown architecture"
 #endif
             // at(): no catch, theme_dark_ theme_light_ should exist
             dark_mode_ = have_dark_system_palette;
