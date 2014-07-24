--- ./src/plugins/batt/batt_sys.h.orig	2014-05-09 09:15:04.000000000 -0400
+++ ./src/plugins/batt/batt_sys.h	2014-05-27 18:14:12.000000000 -0400
@@ -23,6 +23,12 @@
 #ifndef BATT_SYS_H
 #define BATT_SYS_H
 
+/* The states a battery can have */
+#define BATT_FULL               0
+#define BATT_DISCHARGING        1
+#define BATT_CHARGING           2
+#define BATT_CRITICAL           5
+#define BATT_NONE               7
 
 #define BUF_SIZE 1024
 #define ACPI_PATH_SYS_POWER_SUPPY   "/sys/class/power_supply"
@@ -35,7 +41,7 @@
 typedef struct battery {
     int battery_num;
     /* path to battery dir */
-    gchar *path;
+    const gchar *path;			
     /* sysfs file contents */
     int charge_now;
     int energy_now;
@@ -55,10 +61,9 @@
 } battery;
 
 battery *battery_get();
-battery *battery_update( battery *b );
-void battery_print(battery *b, int show_capacity);
+void battery_update( battery *b );
+void battery_print(battery *b);
+void battery_reset(battery *b);
 gboolean battery_is_charging( battery *b );
-gint battery_get_remaining( battery *b );
-void battery_free(battery* bat);
 
 #endif
