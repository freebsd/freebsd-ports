$FreeBSD$
--- electricsheep.c.orig	Tue Jul  3 14:55:00 2001
+++ electricsheep.c	Tue Feb 12 12:58:42 2002
@@ -1223,7 +1223,7 @@
 
     /* create our own group so all workers/children may be killed together
        without hassle */
-    if (-1 == setpgrp())
+    if (-1 == setpgrp(getpid(), getpid()))
 	perror("setpgrp");
     signal(SIGTERM, handle_sig_term);
     signal(SIGINT, handle_sig_term);
