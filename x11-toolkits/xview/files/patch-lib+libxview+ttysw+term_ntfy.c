--- lib/libxview/ttysw/term_ntfy.c.orig	2012-02-07 17:28:16.554359417 -0800
+++ lib/libxview/ttysw/term_ntfy.c	2012-02-07 17:34:31.010651930 -0800
@@ -22,7 +22,7 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
-#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__)
+#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)
 #include <unistd.h>
 #endif
 
@@ -63,7 +63,7 @@
 /* performance: global cache of getdtablesize() */
 extern int      dtablesize_cache;
 
-#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__)
+#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)
 #define GETDTABLESIZE() \
 (dtablesize_cache?dtablesize_cache:(dtablesize_cache=(int)sysconf(_SC_OPEN_MAX)))
 #else
@@ -173,7 +173,7 @@
      * again, this is the place to start looking.
      */
     if (ttysw->pending_remote != ttysw->remote) {
-#if !(defined(__linux__) || defined(__CYGWIN__)) || defined(TIOCREMOTE)
+#if !(defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)) || defined(TIOCREMOTE)
 	if (ioctl(ttysw->ttysw_pty, TIOCREMOTE, &ttysw->pending_remote) < 0)
 	    perror("ioctl: TIOCREMOTE");
 	else
