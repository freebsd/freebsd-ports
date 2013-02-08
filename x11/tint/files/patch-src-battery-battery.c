Index: src/battery/battery.c
===================================================================
--- src/battery/battery.c	(Revision 514)
+++ src/battery/battery.c	(Revision 515)
@@ -24,13 +24,18 @@
 #include <cairo-xlib.h>
 #include <pango/pangocairo.h>
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <machine/apmvar.h>
 #include <err.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #include "window.h"
 #include "server.h"
 #include "area.h"
@@ -59,11 +64,10 @@
 char *path_current_now;
 char *path_status;
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 int apm_fd;
 #endif
 
-
 void update_batterys(void* arg)
 {
 	int i;
@@ -103,7 +107,7 @@
 	path_energy_full = 0;
 	path_current_now = 0;
 	path_status = 0;
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 	apm_fd = -1;
 #endif
 }
@@ -118,7 +122,7 @@
 	if (path_status) g_free(path_status);
 	if (battery_low_cmd) g_free(battery_low_cmd);
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 	if ((apm_fd != -1) && (close(apm_fd) == -1))
 		warn("cannot close /dev/apm");
 #endif
@@ -129,7 +133,7 @@
 {
 	if (!battery_enabled) return;
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 	apm_fd = open("/dev/apm", O_RDONLY);
 	if (apm_fd < 0) {
 		warn("init_battery: failed to open /dev/apm.");
@@ -137,7 +141,7 @@
 		return;
 	}
 
-#else
+#elif !defined(__FreeBSD__)
 	// check battery
 	GDir *directory = 0;
 	GError *error = NULL;
@@ -258,17 +262,21 @@
 
 
 void update_battery() {
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
+#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__)
 	// unused on OpenBSD, silence compiler warnings
 	FILE *fp;
 	char tmp[25];
 	int64_t current_now = 0;
 #endif
+#if defined(__FreeBSD__)
+	int sysctl_out =  0;
+	size_t len = 0;
+#endif
 	int64_t energy_now = 0, energy_full = 0;
 	int seconds = 0;
 	int8_t new_percentage = 0;
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 	struct apm_power_info info;
 	if (ioctl(apm_fd, APM_IOC_GETPOWER, &(info)) < 0)
 		warn("power update: APM_IOC_GETPOWER");
@@ -298,6 +306,45 @@
 
 	new_percentage = info.battery_life;
 
+#elif defined(__FreeBSD__)
+	len = sizeof(sysctl_out);
+
+	if (sysctlbyname("hw.acpi.battery.state", &sysctl_out, &len, NULL, 0) != 0)
+		fprintf(stderr, "power update: no such sysctl");
+
+	// attemp to map the battery state to linux
+	battery_state.state = BATTERY_UNKNOWN;
+
+	switch(sysctl_out) {
+		case 1:
+			battery_state.state = BATTERY_DISCHARGING;
+			break;
+		case 2:
+			battery_state.state = BATTERY_CHARGING;
+			break;
+		default:
+			battery_state.state = BATTERY_FULL;
+			break;
+	}
+
+	// no mapping for freebsd
+	energy_full = 0;
+	energy_now = 0;
+
+	if (sysctlbyname("hw.acpi.battery.time", &sysctl_out, &len, NULL, 0) != 0)
+		seconds = -1;
+	else
+		seconds = sysctl_out * 60;
+
+	// charging or error
+	if (seconds < 0)
+		seconds = 0;
+
+	if (sysctlbyname("hw.acpi.battery.life", &sysctl_out, &len, NULL, 0) != 0)
+		new_percentage = -1;
+	else
+		new_percentage = sysctl_out;
+
 #else
 	fp = fopen(path_status, "r");
 	if(fp != NULL) { 

