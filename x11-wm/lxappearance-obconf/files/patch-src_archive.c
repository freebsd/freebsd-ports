--- src/archive.c.orig	2016-02-20 22:51:21 UTC
+++ src/archive.c
@@ -179,18 +179,17 @@ static gchar* install_theme_to(const gch
     GError *e = NULL;
     gchar *name = NULL;
 
-    argv = g_new(gchar*, 11);
+    argv = g_new(gchar*, 10);
     argv[0] = g_strdup("tar");
     argv[1] = g_strdup("-x");
     argv[2] = g_strdup("-v");
     argv[3] = g_strdup("-z");
-    argv[4] = g_strdup("--wildcards");
-    argv[5] = g_strdup("-f");
-    argv[6] = g_strdup(file);
-    argv[7] = g_strdup("-C");
-    argv[8] = g_strdup(to);
-    argv[9] = g_strdup("*/openbox-3/");
-    argv[10] = NULL;
+    argv[4] = g_strdup("-f");
+    argv[5] = g_strdup(file);
+    argv[6] = g_strdup("-C");
+    argv[7] = g_strdup(to);
+    argv[8] = g_strdup("*/openbox-3/");
+    argv[9] = NULL;
     if (!g_spawn_sync(NULL, argv, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL,
                       &outtxt, &errtxt, &exitcode, &e))
         gtk_msg(GTK_MESSAGE_ERROR, _("Unable to run the \"tar\" command: %s"),
