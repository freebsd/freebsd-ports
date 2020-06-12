--- battstat/acpi-freebsd.c.orig	2020-02-10 11:36:09 UTC
+++ battstat/acpi-freebsd.c
@@ -31,9 +31,13 @@
 
 #include <stdio.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/sysctl.h>
+#include <sys/un.h>
 #include <sys/ioctl.h>
+#if defined(__i386__)
 #include <machine/apm_bios.h>
+#endif
 #include <stdlib.h>
 #include <errno.h>
 #include <unistd.h>
@@ -92,16 +96,36 @@ gboolean
 acpi_freebsd_init(struct acpi_info * acpiinfo)
 {
   int acpi_fd;
+  int event_fd;
 
   g_assert(acpiinfo);
 
-  acpi_fd = open(ACPIDEV, O_RDONLY);
-  if (acpi_fd >= 0) {
-    acpiinfo->acpifd = acpi_fd;
+  if (acpiinfo->acpifd == -1) {
+    acpi_fd = open(ACPIDEV, O_RDONLY);
+    if (acpi_fd >= 0) {
+      acpiinfo->acpifd = acpi_fd;
+    }
+    else {
+      acpiinfo->acpifd = -1;
+      return FALSE;
+    }
   }
-  else {
-    acpiinfo->acpifd = -1;
-    return FALSE;
+
+  event_fd = socket(PF_UNIX, SOCK_STREAM, 0);
+  if (event_fd >= 0) {
+    struct sockaddr_un addr;
+    addr.sun_family = AF_UNIX;
+    strcpy(addr.sun_path, "/var/run/devd.pipe");
+    if (connect(event_fd, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
+      acpiinfo->event_fd = event_fd;
+      acpiinfo->event_inited = TRUE;
+      acpiinfo->channel = g_io_channel_unix_new(event_fd);
+    }
+    else {
+      close(event_fd);
+      acpiinfo->event_fd = -1;
+      acpiinfo->event_inited = FALSE;
+    }
   }
 
   update_battery_info(acpiinfo);
@@ -110,6 +134,65 @@ acpi_freebsd_init(struct acpi_info * acpiinfo)
   return TRUE;
 }
 
+#define ACPI_EVENT_IGNORE	0
+#define ACPI_EVENT_AC		1
+#define ACPI_EVENT_BATTERY_INFO	2
+
+static int parse_acpi_event(GString *buffer)
+{
+  if (strstr(buffer->str, "system=ACPI")) {
+    if (strstr(buffer->str, "subsystem=ACAD"))
+      return ACPI_EVENT_AC;
+    if (strstr(buffer->str, "subsystem=CMBAT"))
+      return ACPI_EVENT_BATTERY_INFO;
+  }
+
+  return ACPI_EVENT_IGNORE;
+}
+
+void acpi_freebsd_update(struct acpi_info *acpiinfo)
+{
+  /* XXX This is needed for systems where devd does not have permissions
+   * to allow for event-driven updates.
+   */
+  update_ac_info(acpiinfo);
+  update_battery_info(acpiinfo);
+}
+
+gboolean acpi_process_event(struct acpi_info *acpiinfo, gboolean *read_error)
+{
+  gsize i;
+  int evt;
+  gboolean result = FALSE;
+  GString *buffer;
+  GIOStatus stat;
+  buffer = g_string_new(NULL);
+
+  *read_error = FALSE;
+  stat = g_io_channel_read_line_string(acpiinfo->channel, buffer, &i, NULL);
+
+  if (stat == G_IO_STATUS_ERROR || stat == G_IO_STATUS_EOF) {
+    *read_error = TRUE;
+    g_string_free(buffer, TRUE);
+    return FALSE;
+  }
+
+  evt = parse_acpi_event(buffer);
+  switch (evt) {
+    case ACPI_EVENT_AC:
+      update_ac_info(acpiinfo);
+      result = TRUE;
+      break;
+    case ACPI_EVENT_BATTERY_INFO:
+      update_battery_info(acpiinfo);
+      result = TRUE;
+      break;
+  }
+
+  g_string_free(buffer, TRUE);
+  return result;
+}
+
 void
 acpi_freebsd_cleanup(struct acpi_info * acpiinfo)
 {
@@ -119,21 +202,12 @@ acpi_freebsd_cleanup(struct acpi_info * acpiinfo)
     close(acpiinfo->acpifd);
     acpiinfo->acpifd = -1;
   }
-}
 
-/* XXX This is a hack since user-land applications can't get ACPI events yet.
- * Devd provides this (or supposedly provides this), but you need to be
- * root to access devd.
- */
-gboolean
-acpi_process_event(struct acpi_info * acpiinfo)
-{
-  g_assert(acpiinfo);
-
-  update_ac_info(acpiinfo);
-  update_battery_info(acpiinfo);
-
-  return TRUE;
+  if (acpiinfo->event_fd >= 0) {
+    g_io_channel_unref(acpiinfo->channel);
+    close(acpiinfo->event_fd);
+    acpiinfo->event_fd = -1;
+  }
 }
 
 gboolean
