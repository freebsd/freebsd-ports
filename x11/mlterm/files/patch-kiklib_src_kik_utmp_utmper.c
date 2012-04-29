--- kiklib/src/kik_utmp_utmper.c.orig	2012-04-29 11:38:18.000000000 +0900
+++ kiklib/src/kik_utmp_utmper.c	2012-04-29 11:39:57.000000000 +0900
@@ -20,8 +20,8 @@
 
 kik_utmp_t
 kik_utmp_new(
-	char *  tty ,
-	char *  host,
+	const char *  tty ,
+	const char *  host,
 	int pty_fd
 	)
 {
