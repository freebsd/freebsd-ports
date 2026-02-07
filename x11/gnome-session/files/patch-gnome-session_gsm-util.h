--- gnome-session/gsm-util.h.orig	2024-03-18 19:30:06 UTC
+++ gnome-session/gsm-util.h
@@ -53,6 +53,7 @@ gboolean    gsm_util_export_activation_environment  (G
 const char * const * gsm_util_get_variable_blacklist(void);
 
 gboolean    gsm_util_export_activation_environment  (GError     **error);
+#ifdef HAVE_SYSTEMD
 gboolean    gsm_util_export_user_environment        (GError     **error);
 gboolean    gsm_util_systemd_unit_is_active         (const char  *unit,
                                                      GError     **error);
@@ -61,6 +62,7 @@ gboolean    gsm_util_systemd_reset_failed           (G
                                                      GError     **error);
 gboolean    gsm_util_systemd_reset_failed           (GError     **error);
 
+#endif
 
 void        gsm_quit                                (void);
 
