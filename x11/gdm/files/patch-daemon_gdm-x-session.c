--- daemon/gdm-x-session.c.orig	2023-03-20 15:42:37 UTC
+++ daemon/gdm-x-session.c
@@ -20,6 +20,7 @@
 #include "config.h"
 
 #include <locale.h>
+#include <limits.h>
 #include <sysexits.h>
 
 #include "gdm-common.h"
@@ -114,7 +115,7 @@ prepare_auth_file (void)
         GError   *error = NULL;
         gboolean  prepared = FALSE;
         Xauth     auth_entry = { 0 };
-        char      localhost[HOST_NAME_MAX + 1] = "";
+        char      localhost[_POSIX_HOST_NAME_MAX + 1] = "";
 
         g_debug ("Preparing auth file for X server");
 
@@ -124,7 +125,7 @@ prepare_auth_file (void)
                 return NULL;
         }
 
-        if (gethostname (localhost, HOST_NAME_MAX) < 0) {
+        if (gethostname (localhost, _POSIX_HOST_NAME_MAX) < 0) {
                 strncpy (localhost, "localhost", sizeof (localhost) - 1);
         }
 
