
--- gui/gdmlogin.c.orig	Mon Dec 31 21:51:17 2001
+++ gui/gdmlogin.c	Tue Jan 29 18:12:12 2002
@@ -3326,7 +3326,9 @@
 static gboolean
 gdm_login_check_exclude (struct passwd *pwent)
 {
+#ifdef HAVE_SHADOW
 	const char * const lockout_passes[] = { "*", "!!", NULL };
+#endif
 	gint i;
 
 	if ( ! GdmAllowRoot && pwent->pw_uid == 0)
@@ -3335,11 +3337,13 @@
 	if ( ! GdmAllowRemoteRoot && ! login_is_local && pwent->pw_uid == 0)
 		return TRUE;
 
+#ifdef HAVE_SHADOW
 	for (i=0 ; lockout_passes[i] != NULL ; i++)  {
 		if (strcmp (lockout_passes[i], pwent->pw_passwd) == 0) {
 			return TRUE;
 		}
 	}
+#endif
 
 	if (GdmExclude != NULL &&
 	    GdmExclude[0] != '\0') {
