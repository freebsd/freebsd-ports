--- programs/xdm/socket.c.orig	Thu Jun  3 05:38:29 2004
+++ programs/xdm/socket.c	Thu Jun  3 05:40:54 2004
@@ -66,6 +66,9 @@
     char *name = localHostname ();
     registerHostname (name, strlen (name));
 
+    if (request_port == 0)
+	return;
+
 #if defined(IPv6) && defined(AF_INET6)
     chooserFd = socket (AF_INET6, SOCK_STREAM, 0);
 #else
