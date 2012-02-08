--- lib/libxview/notify/ndet_loop.c.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/ndet_loop.c	2012-02-02 21:04:53.576391986 -0800
@@ -14,6 +14,7 @@
  * Ndet_loop.c - Notification loop.
  */
 
+#include <sys/param.h>
 #include <xview_private/i18n_impl.h>
 #include <xview_private/ntfy.h>
 #include <xview_private/ndet.h>
@@ -21,7 +22,7 @@
 #include <xview_private/ndis.h>	/* For ndis_dispatch */
 #if !defined(__linux__) && !defined(__CYGWIN__)
 #ifndef SVR4
-#include <syscall.h>
+#include <sys/syscall.h>
 #else /* SVR4 */
 #include <sys/syscall.h>
 #include <sys/poll.h>
@@ -232,7 +233,7 @@
 	     * will return with an EINTR when a signal arrives while IN
 	     * select, not ON THE WAY into select).
 	     */
-#ifndef SVR4
+#if !defined(SVR4) && !(defined(BSD) && (BSD >= 199103))
 #if !defined(__linux__) && !defined(__CYGWIN__)
 	    nfds = syscall(SYS_select,
 			   FD_SETSIZE, &ibits, &obits, &ebits,
