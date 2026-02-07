--- Temperature.h.orig	2010-02-07 07:03:11 UTC
+++ Temperature.h
@@ -29,7 +29,7 @@
 #define VERSION                 "1.5"
 #define INSTANCENAME            "temperature_app"
 #define CLASSNAME               "Temperature_app"
-#define METAR_URL               "http://weather.noaa.gov/pub/data/observations/metar/decoded/%s.TXT"
+#define METAR_URL               "ftp://tgftp.nws.noaa.gov/data/observations/metar/decoded/%s.TXT"
 #define UPDATE_INTERVAL         900
 #define TIME_POS                22
 #define TEMP_POS                35
