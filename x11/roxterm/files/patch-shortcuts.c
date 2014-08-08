--- src/shortcuts.c.orig
+++ src/shortcuts.c
@@ -485,7 +485,7 @@
     cmdv[0] = editor;
     cmdv[1] = filename;
     cmdv[2] = NULL;
-    if (g_spawn_async(NULL, (char **) cmdv, NULL, G_SPAWN_DEFAULT, NULL, NULL,
+    if (g_spawn_async(NULL, (char **) cmdv, NULL, 0, NULL, NULL,
             &pid, &error))
     {
         GFile *f = g_file_new_for_path(filename);
