--- xcut.c.orig	Mon Sep 20 22:55:33 1999
+++ xcut.c	Wed Sep 29 09:50:24 2004
@@ -94,7 +94,7 @@
 	/* Send data to stdout */
 
 	do {
-	    num_written += write(STDOUT_FILENO, buffer, nbytes - num_written);
+	    num_written += write(STDOUT_FILENO, buffer + num_written, nbytes - num_written);
 	} while (num_written < nbytes);
 
 	/* Clean up */
