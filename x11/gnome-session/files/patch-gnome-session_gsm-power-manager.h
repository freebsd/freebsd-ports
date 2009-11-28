--- gnome-session/gsm-power-manager.h.orig	2009-08-26 14:14:35.000000000 -0400
+++ gnome-session/gsm-power-manager.h	2009-08-26 14:15:07.000000000 -0400
@@ -0,0 +1,87 @@
+/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
+ *
+ * power-manager.h: functions for powering down, restarting, and
+ *                  suspending the computer
+ * Copyright (C) 2006 Ray Strode <rstrode@redhat.com>
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; either version 2, or (at your option)
+ * any later version.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, write to the Free Software
+ * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
+ * 02111-1307, USA.
+ */
+
+#ifndef __GSM_POWER_MANAGER_H__
+#define __GSM_POWER_MANAGER_H__
+
+#include <glib.h>
+#include <glib-object.h>
+
+G_BEGIN_DECLS
+
+#define GSM_TYPE_POWER_MANAGER            (gsm_power_manager_get_type ())
+#define GSM_POWER_MANAGER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GSM_TYPE_POWER_MANAGER, GsmPowerManager))
+#define GSM_POWER_MANAGER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GSM_TYPE_POWER_MANAGER, GsmPowerManagerClass))
+#define GSM_IS_POWER_MANAGER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GSM_TYPE_POWER_MANAGER))
+#define GSM_IS_POWER_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GSM_TYPE_POWER_MANAGER))
+#define GSM_POWER_MANAGER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), GSM_TYPE_POWER_MANAGER, GsmPowerManagerClass))
+#define GSM_POWER_MANAGER_ERROR           (gsm_power_manager_error_quark ())
+
+typedef struct _GsmPowerManager         GsmPowerManager;
+typedef struct _GsmPowerManagerClass    GsmPowerManagerClass;
+typedef struct _GsmPowerManagerPrivate  GsmPowerManagerPrivate;
+typedef enum _GsmPowerManagerError      GsmPowerManagerError;
+
+struct _GsmPowerManager
+{
+  GObject parent;
+
+  GsmPowerManagerPrivate *priv;
+};
+
+struct _GsmPowerManagerClass
+{
+  GObjectClass parent_class;
+
+  void (* request_failed) (GsmPowerManager *manager,
+                           GError          *error);
+};
+
+enum _GsmPowerManagerError
+{
+  GSM_POWER_MANAGER_ERROR_SUSPENDING = 0,
+  GSM_POWER_MANAGER_ERROR_HIBERNATING
+};
+
+GType              gsm_power_manager_get_type           (void) G_GNUC_CONST;
+
+GQuark             gsm_power_manager_error_quark        (void);
+
+GsmPowerManager   *gsm_power_manager_new                (void) G_GNUC_MALLOC;
+
+GsmPowerManager   *gsm_get_power_manager                (void);
+
+gboolean           gsm_power_manager_can_suspend        (GsmPowerManager *manager);
+
+gboolean           gsm_power_manager_can_hibernate      (GsmPowerManager *manager);
+
+gboolean           gsm_power_manager_can_power_down     (GsmPowerManager *manager);
+
+gboolean           gsm_power_manager_can_restart        (GsmPowerManager *manager);
+
+void               gsm_power_manager_attempt_suspend    (GsmPowerManager *manager);
+
+void               gsm_power_manager_attempt_hibernate  (GsmPowerManager *manager);
+
+G_END_DECLS
+
+#endif /* __GSM_POWER_MANAGER_H__ */
