--- common/configuration.c.orig	2021-02-15 22:00:52 UTC
+++ common/configuration.c
@@ -346,6 +346,7 @@ config_init (Configuration *config)
     g_hash_table_insert (config->priv->lightdm_keys, "greeters-directory", GINT_TO_POINTER (KEY_SUPPORTED));
     g_hash_table_insert (config->priv->lightdm_keys, "backup-logs", GINT_TO_POINTER (KEY_SUPPORTED));
     g_hash_table_insert (config->priv->lightdm_keys, "dbus-service", GINT_TO_POINTER (KEY_SUPPORTED));
+    g_hash_table_insert (config->priv->lightdm_keys, "smart-xsession-errors", GINT_TO_POINTER (KEY_SUPPORTED));
     g_hash_table_insert (config->priv->lightdm_keys, "logind-load-seats", GINT_TO_POINTER (KEY_DEPRECATED));
 
     g_hash_table_insert (config->priv->seat_keys, "type", GINT_TO_POINTER (KEY_SUPPORTED));
