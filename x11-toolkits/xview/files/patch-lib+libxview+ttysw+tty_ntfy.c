--- lib/libxview/ttysw/tty_ntfy.c.orig	Tue Jun 29 00:17:17 1993
+++ lib/libxview/ttysw/tty_ntfy.c	Sun Oct 12 20:25:29 2003
@@ -171,10 +173,14 @@
      * SIGWINCHes on resize.
      */
     /* Notify process group that terminal has changed. */
+#if !(defined(BSD) && (BSD >= 199103))
     if (ioctl(ttysw->ttysw_tty, TIOCGPGRP, &pgrp) == -1) {
 	perror(XV_MSG("ttysw_sigwinch, can't get tty process group"));
 	return;
     }
+#else
+    pgrp = tcgetpgrp(ttysw->ttysw_pty);
+#endif
     /*
      * Only killpg when pgrp is not tool's.  This is the case of haven't
      * completed ttysw_fork yet (or even tried to do it yet).
@@ -204,7 +210,11 @@
 	return;
     }
     /* Send the signal to the process group of the controlling tty */
+#if !(defined(BSD) && (BSD >= 199103))
     if (ioctl(ttysw->ttysw_tty, TIOCGPGRP, &control_pg) >= 0) {
+#else
+    if ((control_pg = tcgetpgrp(ttysw->ttysw_pty)) >= 0) {
+#endif
 	/*
 	 * Flush our buffers of completed and partial commands. Be sure to do
 	 * this BEFORE killpg, or we'll flush the prompt coming back from the
