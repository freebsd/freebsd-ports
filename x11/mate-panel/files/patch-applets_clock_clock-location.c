--- applets/clock/clock-location.c.orig	2008-04-07 17:17:51.000000000 -0400
+++ applets/clock/clock-location.c	2008-04-07 22:54:31.000000000 -0400
@@ -27,6 +27,8 @@
 #include "clock-marshallers.h"
 #include "set-timezone.h"
 
+#define daylight 1
+
 G_DEFINE_TYPE (ClockLocation, clock_location, G_TYPE_OBJECT)
 
 typedef struct {
