--- ggiterm.c.orig	Fri Oct 22 11:32:34 2004
+++ ggiterm.c	Sun Dec  5 23:39:35 2004
@@ -38,6 +38,8 @@
 
 /* for openpty() */
 #include <sys/ioctl.h> /* some systems (BSD) need it even with OPENPTY_HEADER */
+/* for pid_t, strangely not included by OPENPTY_HEADER */
+#include <sys/types.h>
 #ifdef OPENPTY_HEADER
 # include OPENPTY_HEADER
 #else
@@ -52,8 +54,6 @@
 # include <utmp.h>
 #endif
 
-/* for pid_t, strangely not included by OPENPTY_HEADER */
-#include <sys/types.h>
 /* for execve, read, write */
 #include <unistd.h>
 
