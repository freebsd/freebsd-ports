--- gnome-pty-helper/gnome-pty-helper.c.orig	Wed Nov 27 13:40:01 2002
+++ gnome-pty-helper/gnome-pty-helper.c	Wed Nov 27 13:40:42 2002
@@ -42,6 +42,7 @@
 #include <unistd.h>
 #include <string.h>
 #include <signal.h>
+#include <sys/param.h>
 #include <fcntl.h>
 #include <termios.h>
 #include <errno.h>
@@ -93,7 +94,7 @@
 #endif
 #endif /* CMSG_DATA */
 
-#define CONTROLLEN (sizeof (struct cmsghdr)  + sizeof (int))
+#define CONTROLLEN (sizeof (struct cmsghdr)  + sizeof (long))
 
 static struct cmsghdr *cmptr;
 
