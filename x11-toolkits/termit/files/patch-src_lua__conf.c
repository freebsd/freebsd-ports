--- src/lua_conf.c.orig	2020-02-17 06:02:21 UTC
+++ src/lua_conf.c
@@ -344,9 +344,9 @@ static gchar** termit_system_path()
     const gchar *configSystem = g_getenv("XDG_CONFIG_DIRS");
     gchar* xdgConfigDirs = NULL;
     if (configSystem) {
-        xdgConfigDirs = g_strdup_printf("%s:/etc/xdg", configSystem);
+        xdgConfigDirs = g_strdup_printf("%s:/usr/local/etc/xdg", configSystem);
     } else {
-        xdgConfigDirs = g_strdup("/etc/xdg");
+        xdgConfigDirs = g_strdup("/usr/local/etc/xdg");
     }
     gchar** systemPaths = g_strsplit(xdgConfigDirs, ":", 0);
     g_free(xdgConfigDirs);
