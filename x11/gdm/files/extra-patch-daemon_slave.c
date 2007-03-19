--- daemon/slave.c.orig	Sat Oct 28 22:38:51 2006
+++ daemon/slave.c	Tue Oct 31 12:33:41 2006
@@ -321,8 +321,7 @@ run_session_output (gboolean read_until_
 			break;
 		}
 
-		if G_UNLIKELY (d->xsession_errors_bytes >= MAX_XSESSION_ERRORS_BYTES ||
-			       got_xfsz_signal)
+		if G_UNLIKELY (got_xfsz_signal)
 			continue;
 
 		/* write until we succeed in writing something */
@@ -344,13 +343,6 @@ run_session_output (gboolean read_until_
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
