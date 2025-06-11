--- gnome-session/gsm-consolekit.h.orig	2024-12-30 10:33:15 UTC
+++ gnome-session/gsm-consolekit.h
@@ -0,0 +1,59 @@
+/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
+ *
+ * Copyright (C) 2008 Jon McCann <jmccann@redhat.com>
+ *
+ * This program is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU General Public License as
+ * published by the Free Software Foundation; either version 2 of the
+ * License, or (at your option) any later version.
+ *
+ * This program is distributed in the hope that it will be useful, but
+ * WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, see <http://www.gnu.org/licenses/>.
+ *
+ * Authors:
+ *	Jon McCann <jmccann@redhat.com>
+ */
+
+#ifndef __GSM_CONSOLEKIT_H__
+#define __GSM_CONSOLEKIT_H__
+
+#include <glib.h>
+#include <glib-object.h>
+
+G_BEGIN_DECLS
+
+#define GSM_TYPE_CONSOLEKIT             (gsm_consolekit_get_type ())
+#define GSM_CONSOLEKIT(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GSM_TYPE_CONSOLEKIT, GsmConsolekit))
+#define GSM_CONSOLEKIT_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GSM_TYPE_CONSOLEKIT, GsmConsolekitClass))
+#define GSM_IS_CONSOLEKIT(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GSM_TYPE_CONSOLEKIT))
+#define GSM_IS_CONSOLEKIT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GSM_TYPE_CONSOLEKIT))
+#define GSM_CONSOLEKIT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj), GSM_TYPE_CONSOLEKIT, GsmConsolekitClass))
+
+typedef struct _GsmConsolekit        GsmConsolekit;
+typedef struct _GsmConsolekitClass   GsmConsolekitClass;
+typedef struct _GsmConsolekitPrivate GsmConsolekitPrivate;
+
+struct _GsmConsolekit
+{
+        GObject               parent;
+
+        GsmConsolekitPrivate *priv;
+};
+
+struct _GsmConsolekitClass
+{
+        GObjectClass parent_class;
+};
+
+GType            gsm_consolekit_get_type        (void);
+
+GsmConsolekit   *gsm_consolekit_new             (void) G_GNUC_MALLOC;
+
+G_END_DECLS
+
+#endif /* __GSM_CONSOLEKIT_H__ */
