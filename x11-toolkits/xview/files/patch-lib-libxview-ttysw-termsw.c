--- lib/libxview/ttysw/termsw.c.orig	2012-02-07 17:35:21.611504567 -0800
+++ lib/libxview/ttysw/termsw.c	2012-02-07 17:41:35.657788530 -0800
@@ -418,7 +418,7 @@
 
     /* Set the PTY to operate as a "remote terminal". */
     fd = (int) xv_get(termsw_public, TTY_PTY_FD);
-#if !(defined(__linux__) || defined(__CYGWIN__)) || defined(TIOCREMOTE)
+#if !(defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)) || defined(TIOCREMOTE)
     (void) ioctl(fd, TIOCREMOTE, &on);
 #endif
     ttysw_folio->remote = ttysw_folio->pending_remote = on;
