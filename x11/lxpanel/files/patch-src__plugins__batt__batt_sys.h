--- src/plugins/batt/batt_sys.h.o	2011-09-16 11:12:42.000000000 -0400
+++ src/plugins/batt/batt_sys.h	2011-09-16 11:39:12.000000000 -0400
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
@@ -53,8 +59,8 @@
 
 battery *battery_get();
 void battery_update( battery *b );
-void battery_print(battery *b, int show_capacity);
+void battery_print(battery *b);
+void battery_reset(battery *b);
 gboolean battery_is_charging( battery *b );
-gint battery_get_remaining( battery *b );
 
 #endif
