
$FreeBSD$

--- daemon/slave.c	2001/10/16 06:36:10	1.1
+++ daemon/slave.c	2001/10/16 06:38:57
@@ -1088,7 +1088,10 @@
 	/* this is again informal only, if the greeter does time out it will
 	 * not actually login a user if it's not enabled for this display */
 	if (d->timed_login_ok) {
-		ve_setenv ("GDM_TIMED_LOGIN_OK", ParsedTimedLogin, TRUE);
+		if (ParsedTimedLogin == NULL)
+			ve_setenv ("GDM_TIMED_LOGIN_OK", "", TRUE);
+		else
+			ve_setenv ("GDM_TIMED_LOGIN_OK", ParsedTimedLogin, TRUE);
 	} else {
 		ve_unsetenv ("GDM_TIMED_LOGIN_OK");
 	}
