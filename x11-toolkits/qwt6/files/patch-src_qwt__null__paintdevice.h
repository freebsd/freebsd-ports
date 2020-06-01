--- src/qwt_null_paintdevice.h.orig	2020-05-30 06:48:02 UTC
+++ src/qwt_null_paintdevice.h
@@ -11,6 +11,7 @@
 #define QWT_NULL_PAINT_DEVICE_H 1
 
 #include "qwt_global.h"
+#include <QPainterPath>
 #include <qpaintdevice.h>
 #include <qpaintengine.h>
 
