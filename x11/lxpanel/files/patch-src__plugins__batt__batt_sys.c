--- src/plugins/batt/batt_sys.c.orig	2012-04-16 15:53:13.000000000 -0400
+++ src/plugins/batt/batt_sys.c	2012-09-05 13:21:28.945076259 -0400
@@ -39,26 +39,10 @@
     static int battery_num = 1;
     battery * b = g_new0 ( battery, 1 );
     b->type_battery = TRUE;
-    b->capacity_unit = "mAh";
-    b->energy_full = -1;
-    b->charge_full = -1;
-    b->voltage_now = -1;
-    b->energy_full_design = -1;
-    b->charge_full_design = -1;
-    b->energy_now = -1;
-    b->charge_now = -1;
-    b->current_now = -1;
-    b->power_now = -1;
     b->state = NULL;
-    b->battery_num = battery_num;
-    b->seconds = -1;
-    b->percentage = -1;
-    b->poststr = NULL;
-    battery_num++;
     return b;
 }
 
-
 static gchar* parse_info_file(battery *b, char *sys_file)
 {
     char *buf = NULL;
@@ -97,7 +81,7 @@
     return parse_info_file(b, sys_file);
 }
 
-void battery_print(battery *b, int show_capacity)
+void battery_print(battery *b)
 {
     if ( b->type_battery )
     {
@@ -110,34 +94,13 @@
 		int seconds = b->seconds - 3600 * hours;
 		int minutes = seconds / 60;
 		seconds -= 60 * minutes;
-		printf(", %02d:%02d:%02d%s", hours, minutes, seconds,
-			b->poststr);
+                printf(", %02d:%02d:%02d", hours, minutes, seconds);
 	    } else if (b->poststr != NULL) {
 		printf(", %s", b->poststr);
 	    }
 
 	    printf("\n");
 	    
-	    if (show_capacity && b->charge_full_design > 0) {
-		int percentage = -1;
-		int charge_full = -1;
-		if (b->charge_full <= 100) {
-		    /* some broken systems just give a percentage here */
-		    percentage = b->charge_full;
-		    charge_full = percentage * b->charge_full_design / 100;
-		} else {
-		    percentage = b->charge_full * 100 / b->charge_full_design;
-		    charge_full = b->charge_full;
-		}
-		if (percentage > 100)
-		    percentage = 100;
-
-		printf ("%s %d: design capacity %d %s, "
-			"last full capacity %d %s = %d%%\n",
-			BATTERY_DESC, b->battery_num - 1, b->charge_full_design,
-			b->capacity_unit, charge_full, b->capacity_unit,
-			percentage);
-	    }
 	}
     }
 }
@@ -145,143 +108,48 @@
 
 void battery_update(battery *b)
 {
-    gchar *gctmp;
-
-    /* read from sysfs */
-    b->charge_now = get_gint_from_infofile(b, "charge_now");
-    b->energy_now = get_gint_from_infofile(b, "energy_now");
-
-    b->current_now = get_gint_from_infofile(b, "current_now");
-    b->power_now   = get_gint_from_infofile(b, "power_now");
-    /* FIXME: Some battery drivers report -1000 when the discharge rate is
-     * unavailable. Others use negative values when discharging. Best we can do
-     * is to treat -1 as an error, and take the absolute value otherwise.
-     * Ideally the kernel would not export the sysfs file when the value is not
-     * available. */
-    if (b->current_now < -1)
-	    b->current_now = - b->current_now;
-    if (b->power_now < -1)
-	    b->power_now = - b->power_now;
-
-    b->charge_full = get_gint_from_infofile(b, "charge_full");
-    b->energy_full = get_gint_from_infofile(b, "energy_full");
-
-    b->charge_full_design = get_gint_from_infofile(b, "charge_full_design");
-    b->energy_full_design = get_gint_from_infofile(b, "energy_full_design");
-
-    b->voltage_now = get_gint_from_infofile(b, "voltage_now");
-
-    gctmp = get_gchar_from_infofile(b, "type");
-    b->type_battery = gctmp ? (strcasecmp(gctmp, "battery") == 0) : TRUE;
-
-    b->state = get_gchar_from_infofile(b, "status");
-    if (!b->state)
-	b->state = get_gchar_from_infofile(b, "state");
-    if (!b->state) {
-	if (b->charge_now != -1 || b->energy_now != -1
-		|| b->charge_full != -1 || b->energy_full != -1)
-	    b->state = "available";
-	else
-	    b->state = "unavailable";
-    }
-
-
-    /* convert energy values (in mWh) to charge values (in mAh) if needed and possible */
-
-    if (b->energy_full != -1 && b->charge_full == -1) {
-	if (b->voltage_now != -1) {
-	    b->charge_full = b->energy_full * 1000 / b->voltage_now;
-	} else {
-	    b->charge_full = b->energy_full;
-	    b->capacity_unit = "mWh";
-	}
-    }
-
-    if (b->energy_full_design != -1 && b->charge_full_design == -1) {
-	if (b->voltage_now != -1) {
-	    b->charge_full_design = b->energy_full_design * 1000 / b->voltage_now;
-	} else {
-	    b->charge_full_design = b->energy_full_design;
-	    b->capacity_unit = "mWh";
-	}
-    }
-
-    if (b->energy_now != -1 && b->charge_now == -1) {
-	if (b->voltage_now != -1) {
-	    b->charge_now = b->energy_now * 1000 / b->voltage_now;
-	    if (b->current_now != -1)
-		b->current_now = b->current_now * 1000 / b->voltage_now;
-	} else {
-	    b->charge_now = b->energy_now;
-	}
-    }
-
-    if (b->power_now != -1 && b->current_now == -1) {
-	if (b->voltage_now != -1 && b->voltage_now != 0)
-	    b->current_now = b->power_now * 1000 / b->voltage_now;
-    }
-
-
-    if (b->charge_full < MIN_CAPACITY)
-	b->percentage = 0;
-    else {
-	int promille = (b->charge_now * 1000) / b->charge_full;
-	b->percentage = (promille + 5) / 10; /* round properly */
-    }
-    if (b->percentage > 100)
-	b->percentage = 100;
-
+    char sstmp[ 100 ];
+    int c, state;
+    size_t intlen = sizeof c;
+
+    snprintf(sstmp, sizeof(sstmp), "hw.acpi.battery.life");
+    sysctlbyname(sstmp, &c, &intlen, NULL, 0);
+    b->percentage = c;
+  
+    snprintf(sstmp, sizeof(sstmp), "hw.acpi.battery.state");
+    sysctlbyname(sstmp, &state, &intlen, NULL, 0);
+
+    switch(state) {
+           case BATT_FULL:
+                   b->state = "Full";
+                   break;
+           case BATT_DISCHARGING:
+                   b->state = "Discharging";
+                   break;
+           case BATT_CHARGING:
+                   b->state = "Charging";
+                   break;
+           case BATT_CRITICAL:
+                    b->state = "Critical";
+                    break;
+           case BATT_NONE:
+                    b->state = "Unavailable";
+                    break;
+            default:
+                    b->state = "Unknown";
+                    break;
+  
+      }
+  
+    snprintf(sstmp, sizeof(sstmp), "hw.acpi.battery.time");
+    sysctlbyname(sstmp, &c, &intlen, NULL, 0);
+    b->seconds = c * 60;
 
-    if (b->current_now == -1) {
-	b->poststr = "rate information unavailable";
-	b->seconds = -1;
-    } else if (!strcasecmp(b->state, "charging")) {
-	if (b->current_now > MIN_PRESENT_RATE) {
-	    b->seconds = 3600 * (b->charge_full - b->charge_now) / b->current_now;
-	    b->poststr = " until charged";
-	} else {
-	    b->poststr = "charging at zero rate - will never fully charge.";
-	    b->seconds = -1;
-	}
-    } else if (!strcasecmp(b->state, "discharging")) {
-	if (b->current_now > MIN_PRESENT_RATE) {
-	    b->seconds = 3600 * b->charge_now / b->current_now;
-	    b->poststr = " remaining";
-	} else {
-	    b->poststr = "discharging at zero rate - will never fully discharge.";
-	    b->seconds = -1;
-	}
-    } else {
-	b->poststr = NULL;
-	b->seconds = -1;
-    }
 }
-
-
+  
 battery *battery_get() {
-    GError * error = NULL;
-    const gchar *entry;
-    GDir * dir = g_dir_open( ACPI_PATH_SYS_POWER_SUPPY, 0, &error );
-    battery *b = NULL;
-    if ( dir == NULL ) 
-    {
-	g_warning( "NO ACPI/sysfs support in kernel: %s", error->message );
-	return NULL;
-    }
-    while ( ( entry = g_dir_read_name (dir) ) != NULL )  
-    {
-	b = battery_new();
-	b->path = g_strdup( entry );
-	battery_update ( b );
-	if ( b->type_battery == TRUE ) 
-	    break;
-	/* ignore non-batteries */
-	else { 			
-	    g_free(b);
-	    b = NULL;
-	}
-    }
-    g_dir_close( dir );
+    battery *b = battery_new();
+    battery_update(b);
     return b;
 }
 
@@ -293,10 +161,3 @@
 	     strcasecmp( b->state, "Full" ) == 0
 	     || strcasecmp( b->state, "Charging" ) == 0 );
 }
-
-gint battery_get_remaining( battery *b )
-{
-    return b->seconds;
-}
-
-
