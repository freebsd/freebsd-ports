--- daemon/slave.c.orig	Wed Sep 18 02:25:09 2002
+++ daemon/slave.c	Wed Sep 18 02:25:15 2002
@@ -2327,7 +2327,8 @@
 	if (setusercontext (NULL, pwent, pwent->pw_uid,
 			    LOGIN_SETLOGIN | LOGIN_SETPATH |
 			    LOGIN_SETPRIORITY | LOGIN_SETRESOURCES |
-			    LOGIN_SETUMASK | LOGIN_SETUSER) < 0)
+			    LOGIN_SETUMASK | LOGIN_SETUSER |
+			    LOGIN_SETENV) < 0)
 		gdm_child_exit (DISPLAY_REMANAGE,
 				_("%s: setusercontext() failed for %s. "
 				  "Aborting."), "gdm_slave_session_start",
