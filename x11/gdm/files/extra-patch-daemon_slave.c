--- daemon/slave.c.orig	2007-09-17 10:45:50.000000000 -0400
+++ daemon/slave.c	2007-09-25 13:42:06.000000000 -0400
@@ -373,8 +373,7 @@
 			break;
 		}
 
-		if G_UNLIKELY (d->xsession_errors_bytes >= MAX_XSESSION_ERRORS_BYTES ||
-			       got_xfsz_signal)
+		if G_UNLIKELY (got_xfsz_signal)
 			continue;
 
 		/* write until we succeed in writing something */
@@ -397,13 +396,6 @@
 
 		d->xsession_errors_bytes += r;
 
-		if G_UNLIKELY (d->xsession_errors_bytes >= MAX_XSESSION_ERRORS_BYTES &&
-			       ! got_xfsz_signal) {
-			VE_IGNORE_EINTR (write (d->xsession_errors_fd,
-						"\n...Too much output, ignoring rest...\n",
-						strlen ("\n...Too much output, ignoring rest...\n")));
-		}
-
 		/* there wasn't more then buf available, so no need to try reading
 		 * again, unless we really want to */
 		if (r < sizeof (buf) && ! read_until_eof)
