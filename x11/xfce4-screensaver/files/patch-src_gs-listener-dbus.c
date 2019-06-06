--- src/gs-listener-dbus.c.orig	2019-03-15 02:23:32 UTC
+++ src/gs-listener-dbus.c
@@ -74,10 +74,6 @@ static DBusHandlerResult gs_listener_message_handler  
 #define CK_MANAGER_INTERFACE "org.freedesktop.ConsoleKit.Manager"
 #define CK_SESSION_INTERFACE "org.freedesktop.ConsoleKit.Session"
 
-#define SESSION_NAME         "org.gnome.SessionManager"
-#define SESSION_PATH         "/org/gnome/SessionManager"
-#define SESSION_INTERFACE    "org.gnome.SessionManager"
-
 #define TYPE_MISMATCH_ERROR GS_LISTENER_INTERFACE ".TypeMismatch"
 
 struct GSListenerPrivate {
@@ -108,7 +104,7 @@ typedef struct {
     char     *reason;
     char     *connection;
     guint32   cookie;
-    guint32   foreign_cookie;
+    gint32    fd;
     GTimeVal  since;
 } GSListenerRefEntry;
 
@@ -604,34 +600,44 @@ listener_ref_entry_check (GSListener *listener,
 static void
 add_session_inhibit (GSListener         *listener,
                      GSListenerRefEntry *entry) {
-    DBusMessage     *message;
-    DBusMessage     *reply;
-    DBusMessageIter  iter;
-    DBusMessageIter  reply_iter;
+    DBusMessage     *message, *reply;
+    DBusMessageIter  iter, reply_iter;
     DBusError        error;
-    guint            xid;
-    guint            flags;
+    const gchar     *mode = "block";
+    /* it is a colon-separated list of lock types */
+    const gchar     *what = "idle";
 
     g_return_if_fail (listener != NULL);
 
     dbus_error_init (&error);
 
-    message = dbus_message_new_method_call (SESSION_NAME,
-                                            SESSION_PATH,
-                                            SESSION_INTERFACE,
+#if defined(WITH_SYSTEMD)
+    message = dbus_message_new_method_call (SYSTEMD_LOGIND_SERVICE,
+                                            SYSTEMD_LOGIND_PATH,
+                                            SYSTEMD_LOGIND_INTERFACE,
                                             "Inhibit");
+#elif defined(WITH_CONSOLE_KIT)
+    message = dbus_message_new_method_call (CK_NAME,
+                                            CK_MANAGER_PATH,
+                                            CK_MANAGER_INTERFACE,
+                                            "Inhibit");
+#endif
     if (message == NULL) {
         gs_debug ("Couldn't allocate the dbus message");
         return;
     }
 
     dbus_message_iter_init_append (message, &iter);
-    xid = 0;
-    flags = 8;
-    dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING, &entry->application);
-    dbus_message_iter_append_basic (&iter, DBUS_TYPE_UINT32, &xid);
-    dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING, &entry->reason);
-    dbus_message_iter_append_basic (&iter, DBUS_TYPE_UINT32, &flags);
+    /* what parameter */
+    dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING, &what);
+    /* who parameter */
+    dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING,
+                                    &entry->application);
+    /* why parameter */
+    dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING,
+                                    &entry->reason);
+    /* mode parameter */
+    dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING, &mode);
 
     /* FIXME: use async? */
     reply = dbus_connection_send_with_reply_and_block (listener->priv->connection,
@@ -647,54 +653,23 @@ add_session_inhibit (GSListener         *listener,
     }
 
     dbus_message_iter_init (reply, &reply_iter);
-    dbus_message_iter_get_basic (&reply_iter, &entry->foreign_cookie);
+    if (DBUS_TYPE_UNIX_FD == dbus_message_iter_get_arg_type(&reply_iter))
+        dbus_message_iter_get_basic (&reply_iter, &entry->fd);
 
     dbus_message_unref (reply);
 }
 
 static void
-remove_session_inhibit (GSListener         *listener,
-                        GSListenerRefEntry *entry) {
-    DBusMessage     *message;
-    DBusMessage     *reply;
-    DBusMessageIter  iter;
-    DBusError        error;
-
-    g_return_if_fail (listener != NULL);
-
-    if (entry->foreign_cookie == 0) {
+remove_session_inhibit (GSListenerRefEntry *entry) {
+    if (entry->fd < 0) {
         gs_debug ("Can't remove inhibitor from session: Session cookie not set");
         return;
     }
 
-    dbus_error_init (&error);
-
-    message = dbus_message_new_method_call (SESSION_NAME,
-                                            SESSION_PATH,
-                                            SESSION_INTERFACE,
-                                            "Uninhibit");
-    if (message == NULL) {
-        gs_debug ("Couldn't allocate the dbus message");
+    if (close(entry->fd) < 0) {
+        gs_debug ("Can't close file descriptor");
         return;
     }
-
-    dbus_message_iter_init_append (message, &iter);
-    dbus_message_iter_append_basic (&iter, DBUS_TYPE_UINT32, &entry->foreign_cookie);
-
-    /* FIXME: use async? */
-    reply = dbus_connection_send_with_reply_and_block (listener->priv->connection,
-            message,
-            -1,
-            &error);
-    dbus_message_unref (message);
-
-    if (dbus_error_is_set (&error)) {
-        gs_debug ("%s raised:\n %s\n\n", error.name, error.message);
-        dbus_error_free (&error);
-        return;
-    }
-
-    dbus_message_unref (reply);
 }
 
 static void
@@ -745,7 +720,7 @@ listener_remove_ref_entry (GSListener *listener,
 
     if (entry_type == REF_ENTRY_TYPE_INHIBIT) {
         /* remove inhibit from xfce session */
-        remove_session_inhibit (listener, entry);
+        remove_session_inhibit (entry);
     }
 
     removed = g_hash_table_remove (hash, &cookie);
@@ -977,7 +952,7 @@ listener_ref_entry_remove_for_connection (GSListener  
 
             if (entry->entry_type == REF_ENTRY_TYPE_INHIBIT) {
                 /* remove inhibit from xfce session */
-                remove_session_inhibit (listener, entry);
+                remove_session_inhibit (entry);
             }
 
             g_hash_table_iter_remove (&iter);
