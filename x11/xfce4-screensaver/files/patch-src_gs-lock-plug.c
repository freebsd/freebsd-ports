--- src/gs-lock-plug.c.orig	2025-08-15 14:02:14 UTC
+++ src/gs-lock-plug.c
@@ -26,6 +26,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/utsname.h>
+#include <sys/wait.h>
 #include <time.h>
 #include <unistd.h>
 
@@ -56,6 +57,8 @@
 #include "xfce-bg.h"
 #include "xfce-desktop-utils.h"
 
+#define PGREP_MAX_PROCESS_LEN 15
+
 #define MDM_FLEXISERVER_COMMAND "mdmflexiserver"
 #define MDM_FLEXISERVER_ARGS "--startnew Standard"
 
@@ -179,20 +182,16 @@ process_is_running (const char *name) {
 
 static gboolean
 process_is_running (const char *name) {
-    int num_processes;
-    gchar *command = g_strdup_printf ("pidof %s | wc -l", name);
-    FILE *fp = popen (command, "r");
+    g_return_val_if_fail (strnlen (name, PGREP_MAX_PROCESS_LEN + 1) > PGREP_MAX_PROCESS_LEN, FALSE);
+#ifdef __FreeBSD__
+    gchar *command = g_strdup_printf ("pgrep -ax %s", name);
+#else
+    gchar *command = g_strdup_printf ("pgrep -x %s", name);
+#endif
+    int rc = system (command);
     g_free (command);
 
-    if (fp == NULL)
-        return FALSE;
-
-    if (fscanf (fp, "%d", &num_processes) != 1)
-        num_processes = 0;
-
-    pclose (fp);
-
-    if (num_processes > 0) {
+    if (WIFEXITED (rc) && WEXITSTATUS (rc) == 0) {
         return TRUE;
     } else {
         return FALSE;
