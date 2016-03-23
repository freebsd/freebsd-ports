# Description: Use correct namelen when connecting to i3 socket
# Pull Request: https://github.com/DaveDavenport/rofi/pull/330
--- source/i3-support.c.orig	2015-12-27 18:45:50 UTC
+++ source/i3-support.c
@@ -50,7 +50,7 @@ char *i3_socket_path = NULL;
 void i3_support_focus_window ( Window id )
 {
     i3_ipc_header_t    head;
-    int                s, len;
+    int                s;
     ssize_t            t;
     struct sockaddr_un remote;
     size_t             upm = sizeof ( remote.sun_path );
@@ -68,9 +68,8 @@ void i3_support_focus_window ( Window id
 
     remote.sun_family = AF_UNIX;
     g_strlcpy ( remote.sun_path, i3_socket_path, upm );
-    len = strlen ( remote.sun_path ) + sizeof ( remote.sun_family );
 
-    if ( connect ( s, ( struct sockaddr * ) &remote, len ) == -1 ) {
+    if ( connect ( s, ( struct sockaddr * ) &remote, sizeof ( struct sockaddr_un ) ) == -1 ) {
         fprintf ( stderr, "Failed to connect to I3 (%s): %s\n", i3_socket_path, strerror ( errno ) );
         close ( s );
         return;
