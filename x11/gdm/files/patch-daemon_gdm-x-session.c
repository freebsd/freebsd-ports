--- daemon/gdm-x-session.c.orig	2022-01-12 14:15:56 UTC
+++ daemon/gdm-x-session.c
@@ -114,7 +114,7 @@ prepare_auth_file (void)
         GError   *error = NULL;
         gboolean  prepared = FALSE;
         Xauth     auth_entry = { 0 };
-        char      localhost[HOST_NAME_MAX + 1] = "";
+        char      localhost[256] = "";
 
         g_debug ("Preparing auth file for X server");
 
@@ -124,7 +124,7 @@ prepare_auth_file (void)
                 return NULL;
         }
 
-        if (gethostname (localhost, HOST_NAME_MAX) < 0) {
+        if (gethostname (localhost, 255) < 0) {
                 strncpy (localhost, "localhost", sizeof (localhost) - 1);
         }
 
