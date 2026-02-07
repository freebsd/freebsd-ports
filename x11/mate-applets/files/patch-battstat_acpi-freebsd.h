--- battstat/acpi-freebsd.h.orig	2020-02-10 11:36:09 UTC
+++ battstat/acpi-freebsd.h
@@ -29,61 +29,30 @@
 #define ACPI_LIFE "hw.acpi.battery.life"
 #define ACPI_STATE "hw.acpi.battery.state"
 
-struct acpi_info {
-  gboolean  ac_online;
-  int       acpifd;
-  int       max_capacity;
-  int       low_capacity;
-  int       critical_capacity;
+#if !defined(__i386__)
+struct apm_info {
+  guint    ai_acline;
+  guint    ai_batt_stat;
+  guint    ai_batt_life;
+  int      ai_batt_time;
+  guint    ai_status;
 };
+#endif
 
-gboolean acpi_freebsd_read(struct apm_info *apminfo, struct acpi_info * acpiinfo);
-gboolean acpi_process_event(struct acpi_info * acpiinfo);
-gboolean acpi_freebsd_init(struct acpi_info * acpiinfo);
-void acpi_freebsd_cleanup(struct acpi_info * acpiinfo);
-
-#endif /* __ACPI_FREEBSD_H__ */
-/*
- * Copyright (C) 2004 by Joe Marcus Clarke <marcus@FreeBSD.org>
- *
- *  This program is free software; you can redistribute it and/or modify
- *  it under the terms of the GNU General Public License as published by
- *  the Free Software Foundation; either version 2 of the License, or
- *  (at your option) any later version.
- *
- *  This program is distributed in the hope that it will be useful,
- *  but WITHOUT ANY WARRANTY; without even the implied warranty of
- *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
- *  GNU General Public License for more details.
- *
- *  You should have received a copy of the GNU General Public License
- *  along with this program; if not, write to the Free Software
- *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
- */
-
-#ifndef __ACPI_FREEBSD_H__
-#define __ACPI_FREEBSD_H__
-
-#define ACPIDEV "/dev/acpi"
-
-#define BATT_MIN 0
-#define BATT_MAX 64
-
-#define ACPI_ACLINE "hw.acpi.acline"
-#define ACPI_TIME "hw.acpi.battery.time"
-#define ACPI_LIFE "hw.acpi.battery.life"
-#define ACPI_STATE "hw.acpi.battery.state"
-
 struct acpi_info {
   gboolean  ac_online;
+  gboolean  event_inited;
   int       acpifd;
+  int       event_fd;
   int       max_capacity;
   int       low_capacity;
   int       critical_capacity;
+  GIOChannel * channel;
 };
 
 gboolean acpi_freebsd_read(struct apm_info *apminfo, struct acpi_info * acpiinfo);
-gboolean acpi_process_event(struct acpi_info * acpiinfo);
+void acpi_freebsd_update(struct acpi_info * acpiinfo);
+gboolean acpi_process_event(struct acpi_info * acpiinfo, gboolean *read_error);
 gboolean acpi_freebsd_init(struct acpi_info * acpiinfo);
 void acpi_freebsd_cleanup(struct acpi_info * acpiinfo);
 
