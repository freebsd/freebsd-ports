--- src/Timer.cpp	2025-04-28 14:46:12.228799000 -0700
+++ src/Timer.cpp	2025-04-28 14:46:20.177517000 -0700
@@ -26,6 +26,7 @@
 #include "Database.h"
 #include <X11/Xlib.h>
 #include "Timer.h"
+#include <sys/time.h>
 
 vector<TimerControl*> Timer::items;
 
