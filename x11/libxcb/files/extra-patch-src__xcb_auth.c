--- ./src/xcb_auth.c.orig	Sat Oct  7 18:43:12 2006
+++ ./src/xcb_auth.c	Sun Nov  5 03:44:33 2006
@@ -27,6 +27,7 @@
 
 #include <assert.h>
 #include <X11/Xauth.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <sys/un.h>
