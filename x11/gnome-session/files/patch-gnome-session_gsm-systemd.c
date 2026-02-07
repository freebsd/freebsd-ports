--- gnome-session/gsm-systemd.c.orig	2024-03-18 19:30:06 UTC
+++ gnome-session/gsm-systemd.c
@@ -21,6 +21,8 @@
 #include "config.h"
 #include "gsm-systemd.h"
 
+#ifdef HAVE_SYSTEMD
+
 #include <errno.h>
 #include <string.h>
 #include <stdlib.h>
@@ -1169,4 +1171,13 @@ sd_proxy_signal_cb (GDBusProxy  *proxy,
         }
 }
 
+#else
+
+GsmSystemd *
+gsm_systemd_new (void)
+{
+        return NULL;
+}
+
+#endif
 
