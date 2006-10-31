--- daemon/slave.c.orig	Wed Jun  1 20:49:30 2005
+++ daemon/slave.c	Wed Jun  1 20:50:45 2005
@@ -344,8 +344,7 @@
 			break;
 		}
 
-		if G_UNLIKELY (d->xsession_errors_bytes >= MAX_XSESSION_ERRORS_BYTES ||
-			       got_xfsz_signal)
+		if G_UNLIKELY (got_xfsz_signal)
 			continue;
 
 		/* write until we succeed in writing something */
@@ -367,13 +366,6 @@
 		}
 
 		d->xsession_errors_bytes += r;
-
-		if G_UNLIKELY (d->xsession_errors_bytes >= MAX_XSESSION_ERRORS_BYTES &&
-			       ! got_xfsz_signal) {
-			VE_IGNORE_EINTR (write (d->xsession_errors_fd,
-					     "\n...Too much output, ignoring rest...\n",
-					     strlen ("\n...Too much output, ignoring rest...\n")));
-		}
 
 		/* there wasn't more then buf available, so no need to try reading
 		 * again, unless we really want to */
