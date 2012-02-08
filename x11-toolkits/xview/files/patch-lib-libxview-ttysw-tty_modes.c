--- lib/libxview/ttysw/tty_modes.c.orig	2012-02-07 17:18:34.004531277 -0800
+++ lib/libxview/ttysw/tty_modes.c	2012-02-07 17:25:54.661975084 -0800
@@ -125,7 +125,7 @@
 	/*
 	 * Switch the pty out of remote mode.
 	 */
-#if !(defined(__linux__) || defined(__CYGWIN__)) || defined(TIOCREMOTE)
+#if !(defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)) || defined(TIOCREMOTE)
 	if (ioctl(ttysw->ttysw_pty, TIOCREMOTE, &off) < 0)
 	    perror("ioctl: TIOCREMOTE");
 	else
@@ -278,7 +278,7 @@
      */
     ttysw_getp((Ttysw_view_handle) ttysw_view);
     ttysw->pending_remote = termsw->cooked_echo;
-#if !(defined(__linux__) || defined(__CYGWIN__)) || defined(TIOCREMOTE)
+#if !(defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)) || defined(TIOCREMOTE)
     if (ioctl(ttysw->ttysw_pty, TIOCREMOTE, &ttysw->pending_remote) < 0)
 	perror("ioctl: TIOCREMOTE");
     else
