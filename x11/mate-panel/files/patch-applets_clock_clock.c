--- applets/clock/clock.c.orig	2009-07-01 15:06:23.000000000 +0200
+++ applets/clock/clock.c	2009-07-19 15:59:26.000000000 +0200
@@ -71,6 +71,8 @@
 #include "set-timezone.h"
 #include "system-timezone.h"
 
+#define daylight 1
+
 #define INTERNETSECOND (864)
 #define INTERNETBEAT   (86400)
 
