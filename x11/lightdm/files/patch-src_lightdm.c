--- src/lightdm.c.orig	2026-08-06 19:53:11 UTC
+++ src/lightdm.c
@@ -775,6 +775,8 @@ main (int argc, char **argv)
         config_set_boolean (config_get_instance (), "LightDM", "backup-logs", TRUE);
     if (!config_has_key (config_get_instance (), "LightDM", "dbus-service"))
         config_set_boolean (config_get_instance (), "LightDM", "dbus-service", TRUE);
+    if (!config_has_key (config_get_instance (), "LightDM", "smart-xsession-errors"))
+        config_set_boolean (config_get_instance (), "LightDM", "smart-xsession-errors", FALSE);
     if (!config_has_key (config_get_instance (), "Seat:*", "type"))
         config_set_string (config_get_instance (), "Seat:*", "type", "local");
     if (!config_has_key (config_get_instance (), "Seat:*", "pam-service"))
@@ -830,7 +832,7 @@ main (int argc, char **argv)
     if (!config_has_key (config_get_instance (), "XDMCPServer", "hostname"))
         config_set_string (config_get_instance (), "XDMCPServer", "hostname", g_get_host_name ());
     if (!config_has_key (config_get_instance (), "LightDM", "logind-check-graphical"))
-        config_set_boolean (config_get_instance (), "LightDM", "logind-check-graphical", TRUE);
+        config_set_boolean (config_get_instance (), "LightDM", "logind-check-graphical", FALSE);
 
     /* Override defaults */
     if (log_dir)
