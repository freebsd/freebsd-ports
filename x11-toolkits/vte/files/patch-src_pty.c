--- src/pty.c.orig	Wed Sep 11 02:10:46 2002
+++ src/pty.c	Sat Oct  5 21:07:48 2002
@@ -19,9 +19,10 @@
 #ident "$Id: pty.c,v 1.25 2002/09/11 06:10:46 nalin Exp $"
 #include "../config.h"
 #include <sys/ioctl.h>
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/wait.h>
+#include <sys/uio.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <limits.h>
@@ -525,7 +526,7 @@
 		msg.msg_iovlen = 1;
 		msg.msg_control = control;
 		msg.msg_controllen = sizeof(control);
-		ret = recvmsg(tunnel, &msg, MSG_NOSIGNAL);
+		ret = recvmsg(tunnel, &msg, 0);
 		if (ret == -1) {
 			return;
 		}
