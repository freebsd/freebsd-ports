--- src/Timer.cpp.orig	2005-08-15 05:26:39 UTC
+++ src/Timer.cpp
@@ -26,6 +26,7 @@
 #include "Database.h"
 #include <X11/Xlib.h>
 #include "Timer.h"
+#include <sys/time.h>
 
 vector<TimerControl*> Timer::items;
 
