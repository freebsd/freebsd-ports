--- epplets/E-Power.c.orig	2006-04-16 00:32:43.000000000 +0200
+++ epplets/E-Power.c	2008-03-10 17:12:55.000000000 +0100
@@ -1,9 +1,22 @@
+/*-
+ * Copyright 2008, Pietro Cerutti <gahr@FreeBSD.org> (FreeBSD adaptation)
+ */
+
 #define _GNU_SOURCE
 #include "epplet.h"
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <dirent.h>
 
+#ifdef __FreeBSD__
+#include <fcntl.h>
+#include <sys/ioctl.h>
+#include <dev/acpica/acpiio.h>
+#ifdef __i386__
+#include <machine/apm_bios.h>
+#endif
+#endif
+
 /* Modified by Attila ZIMLER <hijaszu@hlfslinux.hu>, 2003/11/16
    Added ACPI power management support.
 */
@@ -11,6 +24,19 @@
 /* Length of explain strings in /proc/acpi/battery/BAT0 data files */
 #define DATA_EXPLAIN_STR_LEN	25
 
+/* Power management modes */
+#define MODE_NONE 0x0
+#define MODE_APM  0x1
+#define MODE_ACPI 0x2
+static unsigned mode = MODE_NONE;
+
+#ifdef __FreeBSD__
+#define ACPI_DEV "/dev/acpi"
+#define APM_DEV  "/dev/apm"
+static int apm_fd  = -1,
+           acpi_fd = -1;
+#endif
+
 int                 prev_bat_val = 110;
 int                 bat_val = 0;
 int                 time_val = 0;
@@ -31,17 +57,39 @@
 static void
 cb_timer(void *data)
 {
-   struct stat         st;
 
+#ifdef linux
+   struct stat         st;
    if ((stat("/proc/apm", &st) > -1) && S_ISREG(st.st_mode))
-      cb_timer_apm(data);
+      mode = MODE_APM;
    else if ((stat("/proc/acpi", &st) > -1) && S_ISDIR(st.st_mode))
+      mode = MODE_ACPI;
+#elif defined(__FreeBSD__)
+   /*
+    * Try ACPI first, if does not work, revert to APM
+    */
+   if(acpi_fd != -1 || ((acpi_fd = open(ACPI_DEV, O_RDONLY)) != -1))
+      mode = MODE_ACPI;
+   else if(apm_fd != -1 || ((apm_fd = open(APM_DEV, O_RDONLY)) != -1))
+      mode = MODE_APM;
+#else
+   mode = MODE_NONE;
+#endif
+
+
+   if(mode & MODE_APM)
+      cb_timer_apm(data);
+   else if(mode & MODE_ACPI)
       cb_timer_acpi(data);
 }
 
 static void
 cb_timer_acpi(void *data)
 {
+   char current_status[256];
+   int  bat_val = 0;
+
+#ifdef linux
    /* We don't have any data from the remaining percentage, and time directly,
     * so we have to calculate and measure them.
     * (Measure the time and calculate the percentage.)
@@ -57,9 +105,6 @@
    int                 bat_level = 0;
    int                 bat_drain = 1;
 
-   int                 bat_val = 0;
-
-   char                current_status[256];
    char               *line = 0;
    size_t              lsize = 0;
    int                 discharging = 0;
@@ -203,27 +248,74 @@
    else
       snprintf(current_status, sizeof(current_status), "Full");
 
+   /* Final steps before ending the status update. */
+   data = NULL;
+   if (lsize)
+      free(line);
+
+#elif defined(__FreeBSD__)
+   union acpi_battery_ioctl_arg batt;
+   int c;
+   batt.unit = 0;
+   if(ioctl(acpi_fd, ACPIIO_BATT_GET_BATTINFO, &batt) == -1)
+      return;
+
+   /*
+    * Get percent
+    */
+   if(batt.battinfo.cap == -1) {
+      c = snprintf(current_status, sizeof(current_status), "???");
+      bat_val = 0;
+   }
+   else {
+      c = snprintf(current_status, sizeof(current_status), "%d%%",
+            batt.battinfo.cap);
+      bat_val = batt.battinfo.cap;
+   }
+
+   /*
+    * Get online status
+    */
+   if(batt.battinfo.state == ACPI_BATT_STAT_NOT_PRESENT)
+      c += snprintf(&current_status[c], sizeof(current_status) - c, " NONE\n");
+   else if(batt.battinfo.state == ACPI_BATT_STAT_DISCHARG || batt.battinfo.state == ACPI_BATT_STAT_CRITICAL)
+      c += snprintf(&current_status[c], sizeof(current_status) - c, " OFF\n");
+   else
+      c += snprintf(&current_status[c], sizeof(current_status) - c, " ON\n");
+
+   /*
+    * Get remaining time
+    */
+   if(batt.battinfo.min == -1) {
+      if(batt.battinfo.state == ACPI_BATT_STAT_DISCHARG ||
+         batt.battinfo.state == ACPI_BATT_STAT_CRITICAL ||
+         batt.battinfo.state == ACPI_BATT_STAT_NOT_PRESENT)
+      snprintf(&current_status[c], sizeof(current_status) - c, "?:??");
+   }
+   else {
+      snprintf(&current_status[c], sizeof(current_status) - c, "%d:%2d",
+            batt.battinfo.min / 60, batt.battinfo.min % 60);
+   }
+
+#endif
    /* Display current status */
    Epplet_change_label(label, current_status);
    sprintf(current_status, "E-Power-Bat-%i.png", ((bat_val + 5) / 10) * 10);
    Epplet_change_image(image, 44, 24, current_status);
    Epplet_timer(cb_timer, NULL, 5.0, "TIMER");
-
-   /* Final steps before ending the status update. */
-   data = NULL;
-   if (lsize)
-      free(line);
 }
 
 static void
 cb_timer_apm(void *data)
 {
+   char s[256];
+#ifdef linux
    static FILE        *f;
 
    f = fopen("/proc/apm", "r");
    if (f)
      {
-	char                s[256], s1[32], s2[32], s3[32];
+	char                s1[32], s2[32], s3[32];
 	int                 apm_flags, ac_stat, bat_stat, bat_flags;
 	int                 i, hours, minutes, up, up2;
 	char               *s_ptr;
@@ -296,14 +388,57 @@
 	     else
 		s_ptr += sprintf(s_ptr, "%i:%02i", hours, minutes);
 	  }
-	Epplet_change_label(label, s);
+   prev_bat_val = bat_val;
+#elif defined(__FreeBSD__) && defined(__i386__)
+   struct apm_info apm;
+   int c;
+   if(ioctl(apm_fd, APMIO_GETINFO, &apm) == -1)
+      return;
 
+   /*
+    * Get percent
+    */
+   if(apm.ai_batt_life == 0xff) {
+      c = snprintf(s, sizeof(s), "???");
+      bat_val = 0;
+   }
+   else {
+      c = snprintf(s, sizeof(s), "%d%%", apm.ai_batt_life);
+      bat_val = apm.ai_batt_life;
+   }
+
+   /*
+    * Get online status
+    */
+   if(apm.ai_acline == 0xff)
+      c += snprintf(&s[c], sizeof(s) - c, " NONE\n");
+   else if(apm.ai_acline)
+      c += snprintf(&s[c], sizeof(s) - c, " ON\n");
+   else
+      c += snprintf(&s[c], sizeof(s) - c , " OFF\n");
+
+   /*
+    * Get remaining time
+    */
+   if(apm.ai_batt_time == -1) {
+      if(apm.ai_acline == 0xff || !apm.ai_acline)
+         snprintf(&s[c], sizeof(s) - c, "?:??");
+   }
+   else
+      snprintf(&s[c], sizeof(s) - c, "%d:%2d",
+            apm.ai_batt_time / 3600, apm.ai_batt_time / 60 % 60);
+#endif
+
+   /* Display current status */
+	Epplet_change_label(label, s);
 	sprintf(s, "E-Power-Bat-%i.png", ((bat_val + 5) / 10) * 10);
 	Epplet_change_image(image, 44, 24, s);
+#ifdef linux
 	Epplet_timer(cb_timer, NULL, 30.0, "TIMER");
+#else
+	Epplet_timer(cb_timer, NULL, 5.0, "TIMER");
+#endif
 
-	prev_bat_val = bat_val;
-     }
    data = NULL;
 }
 
@@ -351,7 +486,14 @@
 static void
 cb_suspend(void *data)
 {
+#ifdef __FreeBSD__
+   if(mode & MODE_ACPI)
+      system("/usr/sbin/acpiconf -s 5");
+   else if(mode & MODE_APM)
+      system("/usr/sbin/apm -z");
+#else
    system("/usr/bin/apm -s");
+#endif
    return;
    data = NULL;
 }
@@ -359,7 +501,14 @@
 static void
 cb_sleep(void *data)
 {
+#ifdef __FreeBSD__
+   if(mode & MODE_ACPI)
+      system("/usr/sbin/acpiconf -s 1");
+   else if(mode & MODE_APM)
+      system("/usr/sbin/amp -z");
+#else
    system("/usr/bin/apm -S");
+#endif
    return;
    data = NULL;
 }
