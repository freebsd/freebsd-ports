
$FreeBSD$

--- daemon/slave.c.orig	Tue Jan  1 04:48:07 2002
+++ daemon/slave.c	Fri Jan 11 15:51:27 2002
@@ -45,6 +45,11 @@
 #include <time.h>
 #include <syslog.h>
 
+#ifdef HAVE_LOGINCAP
+#include <unistd.h>
+#include <login_cap.h>
+#endif
+
 #include <vicious.h>
 
 #include "gdm.h"
@@ -140,6 +145,8 @@
 static gboolean x_error_occured = FALSE;
 static gboolean gdm_got_usr2 = FALSE;
 
+static void		changeUser(struct passwd *pwent, char *login);
+
 /* ignore handlers */
 static int
 ignore_xerror_handler (Display *disp, XErrorEvent *evt)
@@ -1785,6 +1792,27 @@
 
 }
 
+#ifdef HAVE_LOGINCAP
+void changeUser(struct passwd *pwent, char *login) {
+	if (setsid() == -1)
+		gdm_child_exit (DISPLAY_REMANAGE, _("gdm_slave_session_start: setsid() failed for %s. Aborting."), login);
+	if (setusercontext(NULL, pwent, pwent->pw_uid, LOGIN_SETALL) == -1)
+		gdm_child_exit (DISPLAY_REMANAGE, _("gdm_slave_session_start: setusercontext() failed for %s. Aborting."), login);
+}
+#else
+void changeUser(struct passwd *pwent, char *login) {
+	setpgid(0, 0);
+	umask(022);
+	/* setup the user's correct group */
+	if (setgid(pwent->pw_gid) < 0)
+		gdm_child_exit (DISPLAY_REMANAGE, _("gdm_slave_session_start: Could not setgid %d. Aborting."), pwent->pw_gid);
+	if (initgroups(login, pwent->pw_gid) < 0)
+		gdm_child_exit (DISPLAY_REMANAGE, _("gdm_slave_session_start: initgroups() failed for %s. Aborting."), login);
+	if (setuid(pwent->pw_uid) < 0) 
+		gdm_child_exit (DISPLAY_REMANAGE, _("gdm_slave_session_start: Could not become %s. Aborting."), login);
+}
+#endif
+
 static char *
 dequote (const char *in)
 {
@@ -1840,12 +1871,6 @@
 	if (gnome_session != NULL)
 		ve_setenv ("GDM_GNOME_SESSION", gnome_session, TRUE);
 
-	/* Special PATH for root */
-	if (pwent->pw_uid == 0)
-		ve_setenv ("PATH", GdmRootPath, TRUE);
-	else
-		ve_setenv ("PATH", GdmDefaultPath, TRUE);
-
 	/* Eeeeek, this no lookie as a correct language code, let's
 	 * try unaliasing it */
 	if (strlen (language) < 3 ||
@@ -1853,14 +1878,31 @@
 		language = unaliaslang (language);
 	}
 
-	/* Set locale */
+	changeUser(pwent, login);
+
+	/*
+	 * Set locale. XXX in the HAVE_LOGINCAP case we override user's
+	 * default language, but there is no other way around, because there
+	 * is no way to select "Use user's default language" in the GDM, so
+	 * that we either have to give up ability to select language other
+	 * one specified in the login.conf, or just ignore default setting.
+	 * I selected the latter, which is suboptimal, but at least gives
+	 * some freedom to the user.
+	 */
 	ve_setenv ("LANG", language, TRUE);
 	ve_setenv ("GDM_LANG", language, TRUE);
+
+#ifndef HAVE_LOGINCAP
+
+	/* Special PATH for root */
+	if (pwent->pw_uid == 0) 
+		ve_setenv("PATH", GdmRootPath, TRUE);
+	else
+		ve_setenv("PATH", GdmDefaultPath, TRUE);
+#else
+	 /* Do not reset PATH */
+#endif
     
-	setpgid (0, 0);
-	
-	umask (022);
-	
 	/* setup the verify env vars */
 	if ( ! gdm_verify_setup_env (d))
 		gdm_child_exit (DISPLAY_REMANAGE,
@@ -1870,12 +1912,8 @@
 
 	/* setup egid to the correct group,
 	 * not to leave the egid around */
-	setegid (pwent->pw_gid);
+	/*setegid (pwent->pw_gid);*/
 
-	if (setuid (pwent->pw_uid) < 0) 
-		gdm_child_exit (DISPLAY_REMANAGE,
-				_("gdm_slave_session_start: Could not become %s. Aborting."), login);
-	
 	chdir (home_dir);
 
 	/* anality, make sure nothing is in memory for gnome_config
