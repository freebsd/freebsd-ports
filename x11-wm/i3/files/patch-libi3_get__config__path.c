--- libi3/get_config_path.c.orig	2016-11-08 18:54:01 UTC
+++ libi3/get_config_path.c
@@ -71,7 +71,7 @@ char *get_config_path(const char *overri
 
     /* 4: check for $XDG_CONFIG_DIRS/i3/config */
     if ((xdg_config_dirs = getenv("XDG_CONFIG_DIRS")) == NULL)
-        xdg_config_dirs = "/etc/xdg";
+        xdg_config_dirs = SYSCONFDIR "/xdg";
 
     char *buf = sstrdup(xdg_config_dirs);
     char *tok = strtok(buf, ":");
