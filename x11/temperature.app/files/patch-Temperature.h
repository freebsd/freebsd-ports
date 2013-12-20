--- Temperature.h.bak	2002-04-06 08:44:17.000000000 +0900
+++ Temperature.h	2013-12-07 17:24:28.000000000 +0900
@@ -22,9 +22,11 @@
 #ifndef _TEMPERATURE_H_
 #define _TEMPERATURE_H_
 
-#include <fstream.h>
+#include <fstream>
 #include <X11/Xlib.h>
 
+using std::ifstream;
+
 #define APPNAME                 "Temperature.app"
 #define VERSION                 "1.4"
 #define INSTANCENAME            "temperature_app"
