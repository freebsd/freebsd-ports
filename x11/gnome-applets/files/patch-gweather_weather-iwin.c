--- gweather/weather-iwin.c.orig	Tue Dec 21 18:42:38 2004
+++ gweather/weather-iwin.c	Tue Dec 21 18:42:47 2004
@@ -1,5 +1,6 @@
 /* $Id: patch-gweather_weather-iwin.c,v 1.1 2004/12/22 00:06:21 marcus Exp $ */
 
+#include <sys/types.h>
 #include <regex.h>
 #include <gnome.h>
 #include "weather.h"
