
$FreeBSD$

--- daemon/slave.c.orig	Fri Dec  7 07:56:17 2001
+++ daemon/slave.c	Mon Dec 31 17:30:30 2001
@@ -1860,7 +1860,13 @@
 	setpgid (0, 0);
 	
 	umask (022);
-	
+
+	/* setup the user's correct group */
+    if (setgid (pwent->pw_gid) < 0)
+        gdm_child_exit (DISPLAY_REMANAGE, _("gdm_slave_session_start: Could not setgid %d. Aborting."), pwent->pw_gid);
+    if (initgroups (login, pwent->pw_gid) < 0)
+        gdm_child_exit (DISPLAY_REMANAGE, _("gdm_slave_session_start: initgroups() failed for %s. Aborting."), login);
+
 	/* setup the verify env vars */
 	if ( ! gdm_verify_setup_env (d))
 		gdm_child_exit (DISPLAY_REMANAGE,
