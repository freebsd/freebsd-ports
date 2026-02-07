--- gnome-session/gsm-util.c.orig	2024-03-18 19:30:06 UTC
+++ gnome-session/gsm-util.c
@@ -73,12 +73,6 @@ static const char * const variable_unsetlist[] = {
     "LC_COLLATE",
     "LC_MONETARY",
     "LC_MESSAGES",
-    "LC_PAPER",
-    "LC_NAME",
-    "LC_ADDRESS",
-    "LC_TELEPHONE",
-    "LC_MEASUREMENT",
-    "LC_IDENTIFICATION",
     "LC_ALL",
 
     NULL
@@ -626,6 +620,7 @@ gsm_util_export_activation_environment (GError     **e
         return environment_updated;
 }
 
+#ifdef HAVE_SYSTEMD
 gboolean
 gsm_util_export_user_environment (GError     **error)
 {
@@ -884,6 +879,7 @@ gsm_util_systemd_reset_failed (GError **error)
 
         return TRUE;
 }
+#endif
 
 void
 gsm_util_setenv (const char *variable,
@@ -907,12 +903,14 @@ gsm_util_setenv (const char *variable,
                 g_clear_error (&error);
         }
 
+#ifdef HAVE_SYSTEMD
         /* If this fails, the system user session won't get the updated environment
          */
         if (!gsm_util_update_user_environment (variable, value, &error)) {
                 g_debug ("Could not make systemd aware of %s=%s environment variable: %s", variable, value, error->message);
                 g_clear_error (&error);
         }
+#endif
 }
 
 const char * const *
