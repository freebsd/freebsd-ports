--- src/qwt_painter.h.orig	2020-05-30 06:47:45 UTC
+++ src/qwt_painter.h
@@ -17,6 +17,7 @@
 #include <qpen.h>
 #include <qline.h>
 #include <qpalette.h>
+#include <QPainterPath>
 
 class QPainter;
 class QBrush;
@@ -31,7 +32,6 @@ class QwtColorMap;
 class QwtInterval;
 
 class QTextDocument;
-class QPainterPath;
 
 /*!
   \brief A collection of QPainter workarounds
