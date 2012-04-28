--- xforward.c.orig	1993-06-04 19:30:16.000000000 -0700
+++ xforward.c	2012-04-27 13:20:20.603550383 -0700
@@ -292,7 +292,7 @@
 	struct timeval timeout;
 	struct pend_conn *cur,*prev;
 	pid_t temppid;
-	union wait wstatus;
+	int wstatus;
 	int exitstat,wopts,newoutgoing;
 
 	/* for each entry, call waitpid */
