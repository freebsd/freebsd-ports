--- lib/libxview/ttysw/term_ntfy.c.orig	Sat Aug  6 21:47:27 2005
+++ lib/libxview/ttysw/term_ntfy.c	Sat Aug  6 22:03:25 2005
@@ -22,7 +22,8 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
-#ifdef SVR4
+#include <sys/param.h>
+#if (defined(BSD4_4) || defined(SVR4))
 #include <unistd.h>
 #endif
 
@@ -63,7 +64,7 @@
 /* performance: global cache of getdtablesize() */
 extern int      dtablesize_cache;
 
-#ifdef SVR4
+#if (defined(BSD4_4) || defined(SVR4))
 #define GETDTABLESIZE() \
 (dtablesize_cache?dtablesize_cache:(dtablesize_cache=(int)sysconf(_SC_OPEN_MAX)))
 #else
@@ -173,9 +174,11 @@
      * again, this is the place to start looking.
      */
     if (ttysw->pending_remote != ttysw->remote) {
+#ifdef TIOCREMOTE
 	if (ioctl(ttysw->ttysw_pty, TIOCREMOTE, &ttysw->pending_remote) < 0)
 	    perror("ioctl: TIOCREMOTE");
 	else
+#endif
 	    ttysw->remote = ttysw->pending_remote;
     }
 
