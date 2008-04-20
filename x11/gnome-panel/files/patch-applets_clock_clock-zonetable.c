--- applets/clock/clock-zonetable.c.orig	2008-04-15 16:58:01.000000000 -0400
+++ applets/clock/clock-zonetable.c	2008-04-19 20:32:30.000000000 -0400
@@ -18,8 +18,12 @@
 #define ISO3166_FILE SYSTEM_ZONEINFODIR"/country.tab"
 #else
 #define ZONETAB_FILE SYSTEM_ZONEINFODIR"/zone.tab"
+#ifdef __FreeBSD__
+#define ISO3166_FILE DATADIR"/gnome-panel/iso3166.tab"
+#else
 #define ISO3166_FILE SYSTEM_ZONEINFODIR"/iso3166.tab"
 #endif
+#endif
 
 static GObject *zonetable_singleton = NULL;
 
