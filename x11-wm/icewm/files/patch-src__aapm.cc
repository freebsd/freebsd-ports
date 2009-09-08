--- ./src/aapm.cc.orig	2009-01-25 09:39:51.000000000 -0500
+++ ./src/aapm.cc	2009-09-03 16:12:50.000000000 -0400
@@ -31,8 +31,12 @@
 #include <sys/file.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
+#ifdef i386
 #include <machine/apm_bios.h>
 #endif
+#include <sys/sysctl.h>
+#include <dev/acpica/acpiio.h>
+#endif
 
 #ifdef __NetBSD__
 #include <sys/file.h>
@@ -63,7 +67,7 @@
 
 
 void ApmStr(char *s, bool Tool) {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && defined(i386) 
     struct apm_info ai;
 #elif defined __NetBSD__
     struct apm_power_info ai;
@@ -88,7 +92,7 @@
         error = 1;
         return ;
     }
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && defined(i386)
     if (ioctl(fd,APMIO_GETINFO, &ai) == -1)
     {
         static int error = 0;
@@ -231,6 +235,7 @@
 void YApm::AcpiStr(char *s, bool Tool) {
     char buf[80], buf2[80], bat_info[250];
     FILE *fd;
+    int      acpifd;
     //name of the battery
     char *BATname;
     //battery is present or absent
@@ -250,12 +255,14 @@
     //status of ac-adapter online/offline
     int ACstatus;
     int i;
+    size_t len;
 
     *s='\0';
 
     //assign some default values, in case
     //the file in /proc/acpi will contain unexpected values
     ACstatus = -1;
+#ifndef __FreeBSD__
     if (acpiACName && acpiACName[0] != 0) {
         strcat3(buf, "/proc/acpi/ac_adapter/", acpiACName, "/state", sizeof(buf));
         fd = fopen(buf, "r");
@@ -285,6 +292,17 @@
             fclose(fd);
         }
     }
+#else
+    len = sizeof(i);
+    if (sysctlbyname("hw.acpi.acline", &i, &len, NULL, 0) >= 0) {
+	if (i == 1)
+	    ACstatus = AC_ONLINE;
+	else if (i = 0)
+	    ACstatus = AC_OFFLINE;
+	else
+	    ACstatus = AC_UNKNOWN;
+    }
+#endif
 
     int n = 0;
     for (i = 0; i < batteryNum; i++) {
@@ -299,6 +317,7 @@
         BATrate = -1;
         BATtime_remain = -1;
 
+#ifndef __FreeBSD__
         strcat3(buf, "/proc/acpi/battery/", BATname, "/state", sizeof(buf));
         fd = fopen(buf, "r");
         if (fd == NULL) {
@@ -347,10 +366,43 @@
             }
             fclose(fd);
         }
+#else
+	int      acpifd;
+
+#define ACPIDEV         "/dev/acpi"
+	acpifd = open(ACPIDEV, O_RDONLY);
+	if (acpifd != -1) {
+	    union acpi_battery_ioctl_arg battio;
+	    
+	    battio.unit = i;
+	    if (ioctl(acpifd, ACPIIO_BATT_GET_BATTINFO, &battio) != -1) {
+		if (battio.battinfo.state != ACPI_BATT_STAT_NOT_PRESENT) {
+		    BATpresent = BAT_PRESENT;
+		    if (battio.battinfo.state == 0)
+			BATstatus = BAT_FULL;
+		    else if (battio.battinfo.state & ACPI_BATT_STAT_CHARGING)
+			BATstatus = BAT_CHARGING;
+		    else if (battio.battinfo.state & ACPI_BATT_STAT_DISCHARG)
+			BATstatus = BAT_DISCHARGING;
+		    else
+			BATstatus = BAT_UNKNOWN;
+		    if (battio.battinfo.cap != -1 && acpiBatteries[i]->capacity_full != -1)
+			BATcapacity_remain = acpiBatteries[i]->capacity_full *
+			    battio.battinfo.cap / 100;
+		    if (battio.battinfo.min != -1)
+			BATtime_remain = battio.battinfo.min;
+		    if (battio.battinfo.rate != -1)
+			BATrate = battio.battinfo.rate;
+		} else
+		    BATpresent = BAT_ABSENT;
+	    }
+	}
+#endif
 
         if (BATpresent == BAT_PRESENT) { //battery is present now
             if (acpiBatteries[i]->present == BAT_ABSENT) { //and previously was absent
                 //read full-capacity value
+#ifndef __FreeBSD__
                 strcat3(buf, "/proc/acpi/battery/", BATname, "/info", sizeof(buf));
                 fd = fopen(buf, "r");
                 if (fd != NULL) {
@@ -372,6 +424,21 @@
                     if (BATcapacity_remain > BATcapacity_full && BATcapacity_design > 0)
                         BATcapacity_full = BATcapacity_design;
                 }
+#else
+		union acpi_battery_ioctl_arg battio;
+#define UNKNOWN_CAP 0xffffffff                                                  
+#define UNKNOWN_VOLTAGE 0xffffffff                                              
+	    
+		battio.unit = i;
+		if (ioctl(acpifd, ACPIIO_BATT_GET_BIF, &battio) != -1) {
+		    if (battio.bif.dcap != UNKNOWN_CAP)
+			BATcapacity_design = battio.bif.dcap;
+		    if (battio.bif.lfcap != UNKNOWN_CAP)
+			BATcapacity_full = battio.bif.lfcap;
+                    if (BATcapacity_remain > BATcapacity_full && BATcapacity_design > 0)
+                        BATcapacity_full = BATcapacity_design;
+		}
+#endif
                 acpiBatteries[i]->capacity_full = BATcapacity_full;
             }
             else {
@@ -380,6 +447,11 @@
         }
         acpiBatteries[i]->present = BATpresent;
 
+#ifdef __FreeBSD__
+	close(acpifd);
+#endif
+
+        bat_info[0] = 0;
         if (!Tool &&
             taskBarShowApmTime &&
             BATpresent == BAT_PRESENT &&
@@ -387,7 +459,8 @@
             BATstatus == BAT_DISCHARGING &&
             //did we parse the needed values successfully?
             BATcapacity_full >= 0 && BATcapacity_remain >= 0 && BATrate > 0) {
-            BATtime_remain = (int) (60 * (double)(BATcapacity_remain) / BATrate);
+	    if (BATtime_remain == -1)
+        	BATtime_remain = (int) (60 * (double)(BATcapacity_remain) / BATrate);
             sprintf(bat_info, "%d:%02d", BATtime_remain / 60, BATtime_remain % 60);
         }
         else if (BATpresent == BAT_PRESENT &&
@@ -397,17 +470,19 @@
             sprintf(bat_info, "%3.0f%%",
                     100 * (double)BATcapacity_remain / BATcapacity_full);
         }
-        else {
-            //battery is absent or we didn't parse some needed values
-            bat_info[0] = 0;
-        }
 
         if (BATstatus == BAT_CHARGING) {
             if (Tool)
                 strcat(bat_info, _(" - Charging"));
             else
                 strcat(bat_info, _("C"));
-        }
+	} else if (BATstatus == BAT_FULL && Tool)
+                strcat(bat_info, _(" - Full"));
+
+	if (Tool && BATrate > 0) {
+	    sprintf(buf, " %d", BATrate);
+            strcat(bat_info, buf);
+	}
 
         if ((n > 0) && (*bat_info)) {
             if (Tool)
@@ -738,6 +813,7 @@
 YApm::YApm(YWindow *aParent): YWindow(aParent) {
     struct dirent **de;
     int n, i;
+    size_t s;
     FILE *pmu_info;
                     char buf[80];
                     FILE *fd;
@@ -747,6 +823,7 @@
     fCurrentState = 0;
 
     //search for acpi info first
+#ifndef __FreeBSD__
     n = scandir("/sys/class/power_supply", &de, 0, alphasort);
     if (n < 0) {
         n = scandir("/proc/acpi/battery", &de, 0, alphasort);
@@ -824,7 +901,34 @@
             acpiACName = (char*)malloc(sizeof(char));
             *acpiACName = '\0';
         }
+#else
+    int acpifd;
+    
+    acpifd = open(ACPIDEV, O_RDONLY);
+    if (acpifd != -1) {
+	mode = ACPI;
+
+        //scan for batteries
+        i = 0;
+        while (i < 64 && batteryNum < MAX_ACPI_BATTERY_NUM) {
+	    union acpi_battery_ioctl_arg battio;
+	    
+	    battio.unit = i;
+	    if (ioctl(acpifd, ACPIIO_BATT_GET_BATTINFO, &battio) != -1) {
+    		acpiBatteries[batteryNum] =
+	            (bat_info*)malloc(sizeof(bat_info));
+	    	asprintf(&acpiBatteries[batteryNum]->name, "Battery%d", i);
+	        //initially set as absent, to force reading of
+	        //full-capacity value
+	        acpiBatteries[batteryNum]->present = BAT_ABSENT;
+	        acpiBatteries[batteryNum]->capacity_full = -1;
+	        batteryNum++;
+	    }
+	    i++;
+	}
 
+	asprintf(&acpiACName, "AC1");
+#endif
     } else if ( (pmu_info = fopen("/proc/pmu/info", "r")) != NULL) {
        mode = PMU;
        char line[80];
@@ -870,7 +974,21 @@
 }
 
 void YApm::updateToolTip() {
-    setToolTip(fCurrentState);
+    char s[64] = {' ', ' ', ' ', 0, 0, 0, 0, 0};
+
+    switch (mode) {
+    case ACPI:
+        AcpiStr(s, 1);
+        break;
+    case APM:
+        ApmStr(s, 1);
+        break;
+    case PMU:
+        PmuStr(s, 1);
+        break;
+    }
+
+    setToolTip(s);
 }
 
 int YApm::calcInitialWidth() {
