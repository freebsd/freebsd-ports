--- lib/libxview/ttysw/tty_ntfy.c.orig	2005-03-28 06:41:31.000000000 -0800
+++ lib/libxview/ttysw/tty_ntfy.c	2012-02-03 12:33:30.543933995 -0800
@@ -186,6 +186,8 @@
      * group nevertheless.
      */
     if (ioctl(ttysw->ttysw_pty, TIOCGPGRP, &pgrp) == -1) {
+#elif (defined(BSD) && (BSD >= 199103))
+    if (pgrp = tcgetpgrp(ttysw->ttysw_pty) == -1 ) {
 #elif defined(__CYGWIN__)
     if (tcgetpgrp(ttysw->ttysw_pty) == -1 ) {
 #else
@@ -198,10 +200,12 @@
      * Only killpg when pgrp is not tool's.  This is the case of haven't
      * completed ttysw_fork yet (or even tried to do it yet).
      */
+#if !(defined(BSD) && (BSD >= 199103))
 #if !defined __linux__
     if (getpgrp(0) != pgrp)
 #else
-    if (getpgrp() != pgrp)
+    if (pgrp = getpgrp() != pgrp)
+#endif
 #endif
 	/*
 	 * killpg could return -1 with errno == ESRCH but this is OK.
@@ -230,7 +234,7 @@
 #if defined __linux__
     /* See the comment in ttysw_sigwinch */
     if (ioctl(ttysw->ttysw_pty, TIOCGPGRP, &control_pg) >= 0) {
-#elif defined(__CYGWIN__)
+#elif defined(__CYGWIN__) || defined(BSD) && (BSD >= 199103)
     control_pg = tcgetpgrp(ttysw->ttysw_pty);
     if ( control_pg >= 0 ) {
 #else
