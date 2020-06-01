--- src/qwt_painter_command.h.orig	2020-05-30 06:55:43 UTC
+++ src/qwt_painter_command.h
@@ -15,8 +15,7 @@
 #include <qpixmap.h>
 #include <qimage.h>
 #include <qpolygon.h>
-
-class QPainterPath;
+#include <QPainterPath>
 
 /*!
   QwtPainterCommand represents the attributes of a paint operation
