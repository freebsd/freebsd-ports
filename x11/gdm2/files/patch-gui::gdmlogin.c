--- gui/gdmlogin.c.orig	Tue May 21 00:19:12 2002
+++ gui/gdmlogin.c	Tue May 21 00:20:02 2002
@@ -3419,7 +3419,9 @@
 static gboolean
 gdm_login_check_exclude (struct passwd *pwent)
 {
+#ifdef HAVE_SHADOW
 	const char * const lockout_passes[] = { "*", "!!", NULL };
+#endif
 	gint i;
 
 	if ( ! GdmAllowRoot && pwent->pw_uid == 0)
@@ -3428,11 +3430,13 @@
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
