--- lib/libxview/ttysw/tty_modes.c.orig	Sat Aug  6 21:47:27 2005
+++ lib/libxview/ttysw/tty_modes.c	Sat Aug  6 22:01:01 2005
@@ -125,9 +125,11 @@
 	/*
 	 * Switch the pty out of remote mode.
 	 */
+#   if defined(TIOCREMOTE)
 	if (ioctl(ttysw->ttysw_pty, TIOCREMOTE, &off) < 0)
 	    perror("ioctl: TIOCREMOTE");
 	else
+#   endif
 	    ttysw->remote = ttysw->pending_remote = off;
     }
 
@@ -276,9 +278,11 @@
      */
     ttysw_getp((Ttysw_view_handle) ttysw_view);
     ttysw->pending_remote = termsw->cooked_echo;
+#   if defined(TIOCREMOTE)
     if (ioctl(ttysw->ttysw_pty, TIOCREMOTE, &ttysw->pending_remote) < 0)
 	perror("ioctl: TIOCREMOTE");
     else
+#   endif /* TIOCREMOTE */
 	ttysw->remote = ttysw->pending_remote;
 
     if (!ttysw_waiting_for_pty_input) {
