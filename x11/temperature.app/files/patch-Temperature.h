--- Temperature.h.bak	2016-08-24 21:28:32.665119000 -0400
+++ Temperature.h	2016-08-24 21:26:20.577933000 -0400
@@ -22,14 +22,16 @@
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
 #define CLASSNAME               "Temperature_app"
-#define METAR_URL               "http://weather.noaa.gov/pub/data/observations/metar/decoded/%s.TXT"
+#define METAR_URL               "ftp://tgftp.nws.noaa.gov/data/observations/metar/decoded/%s.TXT"
 #define UPDATE_INTERVAL         900
 #define TIME_POS                22
 #define TEMP_POS                35
