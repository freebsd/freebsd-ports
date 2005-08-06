--- lib/libxview/ttysw/termsw.c.orig	Sat Aug  6 21:47:27 2005
+++ lib/libxview/ttysw/termsw.c	Sat Aug  6 22:04:10 2005
@@ -413,7 +413,9 @@
 
     /* Set the PTY to operate as a "remote terminal". */
     fd = (int) xv_get(termsw_public, TTY_PTY_FD);
+#ifdef TIOCREMOTE
     (void) ioctl(fd, TIOCREMOTE, &on);
+#endif /* TIOCREMOTE */
     ttysw_folio->remote = ttysw_folio->pending_remote = on;
 
     /*
