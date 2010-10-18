--- ./src/plugins/batt/batt_sys.h.orig	2010-10-16 15:13:33.221247000 +0200
+++ ./src/plugins/batt/batt_sys.h	2010-10-16 13:58:18.377264000 +0200
@@ -30,6 +30,13 @@
 #define MIN_PRESENT_RATE 0.01
 #define BATTERY_DESC	"Battery"
 
+/* The states a battery can have */
+#define BATT_FULL               0
+#define BATT_DISCHARGING        1
+#define BATT_CHARGING           2
+#define BATT_CRITICAL           5
+#define BATT_NONE               7
+
 #include <glib.h>
 
 typedef struct battery {
@@ -53,8 +60,7 @@
 
 battery *battery_get();
 void battery_update( battery *b );
-void battery_print(battery *b, int show_capacity);
+void battery_print(battery *b);
 gboolean battery_is_charging( battery *b );
-gint battery_get_remaining( battery *b );
 
 #endif
