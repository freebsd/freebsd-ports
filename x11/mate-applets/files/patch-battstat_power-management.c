--- battstat/power-management.c.orig	2015-01-22 10:16:53.000000000 +0100
+++ battstat/power-management.c	2015-01-22 17:29:57.507849366 +0100
@@ -67,6 +67,10 @@
 
 static const char *apm_readinfo (BatteryStatus *status);
 static int pm_initialised;
+#ifdef HAVE_HAL
+static int using_hal;
+#endif
+static int using_hal = FALSE;
 #ifdef HAVE_UPOWER
 static int using_upower;
 #endif
@@ -178,16 +182,40 @@
 
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 
+#if defined(__i386__)
 #include <machine/apm_bios.h>
+#endif
 #include "acpi-freebsd.h"
 
 static struct acpi_info acpiinfo;
 static gboolean using_acpi;
 static int acpi_count;
+static int acpiwatch;
 static struct apm_info apminfo;
 
+gboolean acpi_freebsd_read(struct apm_info *apminfo, struct acpi_info *acpiinfo);
+
 #define APMDEVICE "/dev/apm"
 
+static gboolean acpi_callback (GIOChannel * chan, GIOCondition cond, gpointer data)
+{
+  gboolean read_error;
+  if (cond & (G_IO_ERR | G_IO_HUP)) {
+    acpi_freebsd_cleanup(&acpiinfo);
+    return FALSE;
+  }
+
+  if (acpi_process_event(&acpiinfo, &read_error)) {
+    acpi_freebsd_read(&apminfo, &acpiinfo);
+  }
+  else if (read_error) {
+    acpi_freebsd_cleanup(&acpiinfo);
+    return FALSE;
+  }
+
+  return TRUE;
+}
+
 static const char *
 apm_readinfo (BatteryStatus *status)
 {
@@ -195,21 +223,27 @@
 
   if (DEBUG) g_print("apm_readinfo() (FreeBSD)\n");
 
-  if (using_acpi) {
+  if (using_acpi && (!acpiinfo.event_inited || acpiinfo.event_fd >= 0)) {
     if (acpi_count <= 0) {
       acpi_count = 30;
-      acpi_process_event(&acpiinfo);
+      if (!acpiinfo.event_inited) {
+        acpi_freebsd_update(&acpiinfo);
+      }
       if (acpi_freebsd_read(&apminfo, &acpiinfo) == FALSE)
         return ERR_FREEBSD_ACPI;
     }
     acpi_count--;
   }
-  else
-  {
-    /* This is how I read the information from the APM subsystem under
-       FreeBSD.  Each time this functions is called (once every second)
-       the APM device is opened, read from and then closed.
-    */
+  else if (using_acpi && acpiinfo.event_inited) {
+    if (acpi_freebsd_init(&acpiinfo)) {
+      acpiwatch = g_io_add_watch (acpiinfo.channel,
+          G_IO_IN | G_IO_ERR | G_IO_HUP,
+	  acpi_callback, NULL);
+      acpi_freebsd_read(&apminfo, &acpiinfo);
+    }
+  }
+  else {
+#if defined(__i386__)
     fd = open(APMDEVICE, O_RDONLY);
     if (fd == -1) {
       return ERR_OPEN_APMDEV;
@@ -222,6 +256,9 @@
 
     if(apminfo.ai_status == 0)
       return ERR_APM_E;
+#else
+    return ERR_OPEN_APMDEV;
+#endif
   }
 
   status->present = TRUE;
@@ -483,6 +520,12 @@
   }
   else
     using_acpi = FALSE;
+
+  if (using_acpi && acpiinfo.event_fd >= 0) {
+    acpiwatch = g_io_add_watch (acpiinfo.channel,
+       G_IO_IN | G_IO_ERR | G_IO_HUP,
+       acpi_callback, NULL);
+  }
 #endif
   pm_initialised = 1;
 
@@ -516,6 +559,9 @@
   }
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
   if (using_acpi) {
+    if (acpiwatch != 0)
+      g_source_remove(acpiwatch);
+    acpiwatch = 0;
     acpi_freebsd_cleanup(&acpiinfo);
   }
 #endif
