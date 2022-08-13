--- src/lightdm.c.orig	2022-07-10 21:17:23 UTC
+++ src/lightdm.c
@@ -813,7 +813,7 @@ main (int argc, char **argv)
     if (!config_has_key (config_get_instance (), "XDMCPServer", "hostname"))
         config_set_string (config_get_instance (), "XDMCPServer", "hostname", g_get_host_name ());
     if (!config_has_key (config_get_instance (), "LightDM", "logind-check-graphical"))
-        config_set_boolean (config_get_instance (), "LightDM", "logind-check-graphical", TRUE);
+        config_set_boolean (config_get_instance (), "LightDM", "logind-check-graphical", FALSE);
 
     /* Override defaults */
     if (log_dir)
