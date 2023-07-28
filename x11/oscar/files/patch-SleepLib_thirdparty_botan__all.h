--- SleepLib/thirdparty/botan_all.h
+++ SleepLib/thirdparty/botan_all.h
@@ -22,5 +22,8 @@
 #ifdef Q_OS_MACOS
 #include "botan_macos.h"
 #endif
+#ifdef Q_OS_FREEBSD
+#include "botan_freebsd.h"
+#endif
 
 #endif // BOTAN_ALL_H
