--- src/EventHandler.hh.orig	Mon Jun 17 19:17:21 2002
+++ src/EventHandler.hh	Mon Jun 17 19:21:08 2002
@@ -15,7 +15,7 @@
 #define __EventHandler_hh
 
 #include <sys/types.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include <X11/Xlib.h>
 #include <hash_set.h>
 
@@ -64,7 +64,7 @@
     Waimea *waimea;
     ResourceHandler *rh;
     Window last_click_win;
-    struct timeb last_click;
+    struct timeval last_click;
 };
 
 Bool eventmatch(WaAction *, EventDetail *);
