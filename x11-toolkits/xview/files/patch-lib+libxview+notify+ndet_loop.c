--- lib/libxview/notify/ndet_loop.c.orig	Tue Jun 29 07:18:19 1993
+++ lib/libxview/notify/ndet_loop.c	Sun Apr  2 03:32:17 2000
@@ -14,13 +14,14 @@ static char     sccsid[] = "@(#)ndet_loo
  * Ndet_loop.c - Notification loop.
  */
 
+#include <sys/param.h>
 #include <xview_private/i18n_impl.h>
 #include <xview_private/ntfy.h>
 #include <xview_private/ndet.h>
 #include <xview_private/nint.h>
 #include <xview_private/ndis.h>	/* For ndis_dispatch */
 #ifndef SVR4
-#include <syscall.h>
+#include <sys/syscall.h>
 #else SVR4
 #include <sys/syscall.h>
 #include <sys/poll.h>
@@ -224,7 +225,8 @@ notify_start()
 	     * will return with an EINTR when a signal arrives while IN
 	     * select, not ON THE WAY into select).
 	     */
-#ifndef SVR4
+
+#if !defined(SVR4) && !(defined(BSD) && (BSD >= 199103))
 	    nfds = syscall(SYS_select,
 			   FD_SETSIZE, &ibits, &obits, &ebits,
 		 (sigisempty(&ndet_sigs_received)) ? timer : &ndet_polling_tv);
