--- ESPHamClock.ino.orig	2022-07-02 11:59:16 UTC
+++ ESPHamClock.ino
@@ -1,6 +1,9 @@
 /* HamClock
  */
 
+#if defined(__FreeBSD__)
+#include <execinfo.h>
+#endif
 
 // glue
 #include "HamClock.h"
@@ -1605,7 +1608,7 @@ static void drawUptime(bool force)
     // draw two most significant units if change
     if (upsecs < 60) {
         prepUptime();
-        tft.print(upsecs); tft.print(F("s "));
+        tft.print((long)upsecs); tft.print(F("s "));
     } else if (upsecs < 3600) {
         prepUptime();
         tft.print(mins); tft.print(F("m "));
