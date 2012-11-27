--- log.h.orig	2012-06-26 10:20:14.000000000 +0200
+++ log.h	2012-11-25 20:00:39.294546666 +0100
@@ -1,6 +1,12 @@
 #ifndef _LOG_H_
 #define _LOG_H_
 
+#ifdef USE_CONSOLEKIT
+#include "Ck.h"
+#endif
+#ifdef USE_CONSOLEKIT
+#include "PAM.h"
+#endif
 #include "const.h"
 #include <fstream>
 
