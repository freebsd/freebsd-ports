--- applets/clock/clock.c.orig	2008-02-26 14:17:49.000000000 +0100
+++ applets/clock/clock.c	2008-02-26 18:01:17.000000000 +0100
@@ -84,6 +84,8 @@
 
 #define FALLBACK_CONFIG_TOOL "time-admin"
 
+#define daylight 1
+
 static const char *clock_config_tools [] = {
 	CLOCK_TIME_UTILITY,
 	FALLBACK_CONFIG_TOOL
