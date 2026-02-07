--- gnome-session/gsm-system.c.orig	2024-03-18 19:30:06 UTC
+++ gnome-session/gsm-system.c
@@ -25,6 +25,9 @@
 
 #include "gsm-systemd.h"
 
+#ifdef HAVE_CONSOLEKIT
+#include "gsm-consolekit.h"
+#endif
 
 enum {
         REQUEST_COMPLETED,
@@ -266,6 +269,15 @@ gsm_get_system (void)
                         g_debug ("Using systemd for session tracking");
                 }
         }
+
+#ifdef HAVE_CONSOLEKIT
+        if (system == NULL) {
+                system = GSM_SYSTEM (gsm_consolekit_new ());
+                if (system != NULL) {
+                        g_debug ("Using ConsoleKit for session tracking");
+                }
+        }
+#endif
 
         if (system == NULL) {
                 system = g_object_new (gsm_system_null_get_type (), NULL);
