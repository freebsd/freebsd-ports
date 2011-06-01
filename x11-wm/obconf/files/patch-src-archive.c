--- src/archive.c.orig	2011-06-01 14:00:24.000000000 +0000
+++ src/archive.c	2011-06-01 14:00:49.000000000 +0000
@@ -178,13 +178,12 @@
     argv[1] = g_strdup("-x");
     argv[2] = g_strdup("-v");
     argv[3] = g_strdup("-z");
-    argv[4] = g_strdup("--wildcards");
-    argv[5] = g_strdup("-f");
-    argv[6] = g_strdup(file);
-    argv[7] = g_strdup("-C");
-    argv[8] = g_strdup(to);
-    argv[9] = g_strdup(glob);
-    argv[10] = NULL;
+    argv[4] = g_strdup("-f");
+    argv[5] = g_strdup(file);
+    argv[6] = g_strdup("-C");
+    argv[7] = g_strdup(to);
+    argv[8] = g_strdup(glob);
+    argv[9] = NULL;
     if (!g_spawn_sync(NULL, argv, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL,
                       &outtxt, &errtxt, &exitcode, &e))
         gtk_msg(GTK_MESSAGE_ERROR, _("Unable to run the \"tar\" command: %s"),


