--- daemon/gdm-session.c
+++ daemon/gdm-session.c
@@ -970,28 +970,6 @@ allow_worker_function (GDBusAuthObserver *observer,
         return FALSE;
 }
 
-static GPid
-credentials_get_unix_pid (GCredentials *credentials)
-{
-        GPid pid = 0;
-        gpointer native_credentials = NULL;
-
-#ifdef __linux__
-        native_credentials = g_credentials_get_native (credentials, G_CREDENTIALS_TYPE_LINUX_UCRED);
-        pid = (GPid) ((struct ucred *) native_credentials)->pid;
-#elif defined (__FreeBSD__)
-        native_credentials = g_credentials_get_native (credentials, G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED);
-        pid = (GPid) ((struct cmsgcred *) native_credentials)->cmcred_pid;
-#elif defined (__OpenBSD__)
-        native_credentials = g_credentials_get_native (credentials, G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED);
-        pid = (GPid) ((struct sockpeercred *) native_credentials)->pid;
-#else
-#error "platform not supported, need mechanism to detect pid of connected process"
-#endif
-
-        return pid;
-}
-
 static gboolean
 register_worker (GdmDBusWorkerManager  *worker_manager_interface,
                  GDBusMethodInvocation *invocation,
@@ -1021,7 +999,7 @@ register_worker (GdmDBusWorkerManager  *worker_manager_interface,
                                     connection_node);
 
         credentials = g_dbus_connection_get_peer_credentials (connection);
-        pid = credentials_get_unix_pid (credentials);
+        pid = g_credentials_get_unix_pid (credentials, NULL);
 
         conversation = find_conversation_by_pid (self, (GPid) pid);
 
@@ -1479,7 +1457,7 @@ on_outside_connection_closed (GDBusConnection *connection,
                             connection);
 
         credentials = g_dbus_connection_get_peer_credentials (connection);
-        pid_of_client = credentials_get_unix_pid (credentials);
+        pid_of_client = g_credentials_get_unix_pid (credentials, NULL);
 
         g_signal_emit (G_OBJECT (self),
                        signals [CLIENT_DISCONNECTED],
@@ -1531,7 +1509,7 @@ handle_connection_from_outside (GDBusServer      *server,
         }
 
         credentials = g_dbus_connection_get_peer_credentials (connection);
-        pid_of_client = credentials_get_unix_pid (credentials);
+        pid_of_client = g_credentials_get_unix_pid (credentials, NULL);
 
         g_signal_emit (G_OBJECT (self),
                        signals [CLIENT_CONNECTED],
