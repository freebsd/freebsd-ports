Index: programs/xdm/socket.c
===================================================================
RCS file: /cvs/xorg/xc/programs/xdm/socket.c,v
retrieving revision 1.2
diff -u -r1.2 socket.c
--- programs/xdm/socket.c	23 Apr 2004 19:54:42 -0000	1.2
+++ programs/xdm/socket.c	6 Jul 2004 00:28:43 -0000
@@ -67,6 +67,9 @@
     char *name = localHostname ();
     registerHostname (name, strlen (name));
 
+    if (request_port == 0)
+	return;
+
 #if defined(IPv6) && defined(AF_INET6)
     chooserFd = socket (AF_INET6, SOCK_STREAM, 0);
     if (chooserFd == -1)
