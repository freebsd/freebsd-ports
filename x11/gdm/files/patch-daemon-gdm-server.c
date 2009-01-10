--- daemon/gdm-server.c.orig	2008-03-17 19:11:00.000000000 -0400
+++ daemon/gdm-server.c	2008-08-25 16:11:10.000000000 -0400
@@ -44,6 +44,10 @@
 #include "gdm-common.h"
 #include "gdm-signal-handler.h"
 
+#include "gdm-settings.h"
+#include "gdm-settings-direct.h"
+#include "gdm-settings-keys.h"
+
 #include "gdm-server.h"
 
 extern char **environ;
@@ -77,6 +81,7 @@ struct GdmServerPrivate
         char    *parent_display_name;
         char    *parent_auth_file;
         char    *chosen_hostname;
+        char    *vt;
 
         guint    child_watch_id;
 };
@@ -306,7 +311,7 @@ gdm_server_resolve_command_line (GdmServ
                 argv[len++] = g_strdup ("tcp");
         }
 
-        if (vtarg != NULL && ! gotvtarg) {
+        if (vtarg != NULL && ! gotvtarg && strncmp (server->priv->display_name, ":0", 2) == 0) {
                 argv[len++] = g_strdup (vtarg);
         }
 
@@ -673,7 +678,7 @@ gdm_server_start (GdmServer *server)
         gboolean res;
 
         /* fork X server process */
-        res = gdm_server_spawn (server, NULL);
+        res = gdm_server_spawn (server, server->priv->vt);
 
         return res;
 }
@@ -925,12 +930,33 @@ static void
 gdm_server_init (GdmServer *server)
 {
 
+        int vt;
+        gboolean has_vt;
+        GdmSettings *settings = NULL;
         server->priv = GDM_SERVER_GET_PRIVATE (server);
 
+
+        settings = gdm_settings_new();
+        if (settings == NULL) {
+                g_assert ("Unable to initialize settings");
+        }
+
+        if (! gdm_settings_direct_init (settings, GDMCONFDIR "/gdm.schemas", "/")) {
+                g_assert ("Unable to initialize settings");
+        }
+
+        has_vt =  gdm_settings_direct_get_int (GDM_KEY_VT, &vt);
+
+        g_object_unref (settings);
+
         server->priv->pid = -1;
         server->priv->command = g_strdup (X_SERVER " -br -verbose");
         server->priv->log_dir = g_strdup (LOGDIR);
 
+        if (has_vt) {
+                server->priv->vt = g_strdup_printf ("vt %d", vt);
+        }
+
         add_ready_handler (server);
 }
 
