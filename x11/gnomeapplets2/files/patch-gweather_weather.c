--- gweather/weather.c.orig	Tue Mar  1 04:34:33 2005
+++ gweather/weather.c	Tue Mar  1 12:36:54 2005
@@ -20,7 +20,9 @@
 #include <string.h>
 #include <ctype.h>
 #include <math.h>
+#ifndef __FreeBSD__
 #include <values.h>
+#endif
 
 #ifdef __FreeBSD__
 #include <sys/types.h>
