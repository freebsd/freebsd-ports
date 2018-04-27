--- kcms/keyboard/kcmmisc.cpp.orig	2015-01-08 16:15:45 UTC
+++ kcms/keyboard/kcmmisc.cpp
@@ -40,6 +40,7 @@
 
 #include <X11/Xlib.h>
 
+#include <math.h>
 
 KCMiscKeyboardWidget::KCMiscKeyboardWidget(QWidget *parent)
 	: QWidget(parent),
