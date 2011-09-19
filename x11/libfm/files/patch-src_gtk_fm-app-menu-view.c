--- src/gtk/fm-app-menu-view.c.o	2011-09-19 11:53:52.000000000 -0400
+++ src/gtk/fm-app-menu-view.c	2011-09-19 11:54:35.000000000 -0400
@@ -136,7 +136,8 @@
         oldenv = g_strdup(g_getenv("XDG_MENU_PREFIX"));
         g_setenv("XDG_MENU_PREFIX", "lxde-", TRUE);
         menu_cache = menu_cache_lookup("applications.menu");
-        g_setenv("XDG_MENU_PREFIX", oldenv, TRUE);
+	// Causing crashes when using "OpenWith" menus
+        //g_setenv("XDG_MENU_PREFIX", oldenv, TRUE);
         g_free(oldenv);
 
         if(menu_cache)
