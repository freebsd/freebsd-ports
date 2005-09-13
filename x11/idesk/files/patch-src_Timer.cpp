--- src/Timer.cpp.orig	Mon Aug 15 07:26:39 2005
+++ src/Timer.cpp	Tue Sep 13 23:14:32 2005
@@ -26,6 +26,7 @@
 #include "Database.h"
 #include <X11/Xlib.h>
 #include "Timer.h"
+#include <sys/time.h>
 
 vector<TimerControl*> Timer::items;
 
