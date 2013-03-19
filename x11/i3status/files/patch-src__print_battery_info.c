--- ./src/print_battery_info.c.orig	2013-03-19 21:06:48.190385644 +0100
+++ ./src/print_battery_info.c	2013-03-19 21:06:52.551387042 +0100
@@ -234,6 +234,15 @@
                 minutes -= (hours * 60);
                 (void)snprintf(remainingbuf, sizeof(remainingbuf), "%02dh%02d",
                                max(hours, 0), max(minutes, 0));
+		if (strncmp(threshold_type, "percentage", strlen(threshold_type)) == 0
+		    && present_rate < low_threshold) {
+			START_COLOR("color_bad");
+			colorful_output = true;
+		} else if (strncmp(threshold_type, "time", strlen(threshold_type)) == 0
+			   && remaining < (u_int) low_threshold) {
+			START_COLOR("color_bad");
+			colorful_output = true;
+		}
         }
 #elif defined(__OpenBSD__)
 	/*
