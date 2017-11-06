--- src/x-server-local.c.orig	2016-12-09 00:50:21 UTC
+++ src/x-server-local.c
@@ -549,17 +549,13 @@ x_server_local_start (DisplayServer *display_server)
         }
     }
 
-    /* Pass through library variables */
-    if (g_getenv ("LD_PRELOAD"))
-        process_set_env (server->priv->x_server_process, "LD_PRELOAD", g_getenv ("LD_PRELOAD"));
-    if (g_getenv ("LD_LIBRARY_PATH"))
-        process_set_env (server->priv->x_server_process, "LD_LIBRARY_PATH", g_getenv ("LD_LIBRARY_PATH"));
-    if (g_getenv ("PATH"))
-        process_set_env (server->priv->x_server_process, "PATH", g_getenv ("PATH"));
-
     /* Variable required for regression tests */
     if (g_getenv ("LIGHTDM_TEST_ROOT"))
+    {
         process_set_env (server->priv->x_server_process, "LIGHTDM_TEST_ROOT", g_getenv ("LIGHTDM_TEST_ROOT"));
+        process_set_env (server->priv->x_server_process, "LD_PRELOAD", g_getenv ("LD_PRELOAD"));
+        process_set_env (server->priv->x_server_process, "LD_LIBRARY_PATH", g_getenv ("LD_LIBRARY_PATH"));
+    }
 
     result = process_start (server->priv->x_server_process, FALSE);
 
