--- src/x-server.c.orig	2016-06-17 04:53:18 UTC
+++ src/x-server.c
@@ -143,7 +143,7 @@ x_server_connect_session (DisplayServer 
     {
         gchar *t;
 
-        t = g_strdup_printf ("/dev/tty%d", vt);
+        t = g_strdup_printf ("/dev/ttyv%d", vt-1);
         session_set_tty (session, t);
         g_free (t);
 
