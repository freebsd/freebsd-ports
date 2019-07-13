--- src/qwt_clipper.cpp.orig	2018-09-16 20:18:22 UTC
+++ src/qwt_clipper.cpp
@@ -7,7 +7,8 @@
  * modify it under the terms of the Qwt License, Version 1.0
  *****************************************************************************/
 
-#include <qrect.h>
+#include <QList>
+#include <QRect>
 #include "qwt_math.h"
 #include "qwt_clipper.h"
 
