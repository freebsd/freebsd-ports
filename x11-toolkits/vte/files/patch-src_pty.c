--- src/pty.c.orig	Tue May 13 01:18:15 2003
+++ src/pty.c	Tue May 13 01:26:22 2003
@@ -48,6 +48,10 @@
 #include "../gnome-pty-helper/gnome-pty.h"
 #endif
 
+#ifdef __FreeBSD__
+#define HAVE_RECVMSG 1
+#endif
+
 #ifdef MSG_NOSIGNAL
 #define PTY_RECVMSG_FLAGS MSG_NOSIGNAL
 #else
