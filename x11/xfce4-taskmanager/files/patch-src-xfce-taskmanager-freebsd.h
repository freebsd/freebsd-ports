--- src/xfce-taskmanager-freebsd.h.orig     Thu Jan  1 01:00:00 1970
+++ src/xfce-taskmanager-freebsd.h  Thu Feb  1 11:54:05 2007
@@ -0,0 +1,24 @@
+#ifndef FREEBSD_H
+#define FREEBSD_H
+
+#include <glib.h>
+#include <pwd.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <stdlib.h>
+#include <string.h>
+#include <limits.h>
+#include <fcntl.h>
+#include <paths.h>
+#include <nlist.h>
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+
+#include "types.h"
+
+struct task get_task_details(struct kinfo_proc *);
+GArray *get_task_list();
+
+#endif
