--- daemon/slave.c.orig	Tue May 21 00:04:14 2002
+++ daemon/slave.c	Tue May 21 00:17:55 2002
@@ -26,6 +26,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#ifdef HAVE_LOGINCAP
+#include <login_cap.h>
+#endif
+
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -2008,6 +2012,7 @@
 		   const char *session,
 		   const char *save_session,
 		   const char *language,
+		   gboolean def_language,
 		   const char *gnome_session,
 		   gboolean usrcfgok,
 		   gboolean savesess,
@@ -2023,6 +2028,11 @@
 
 	gdm_clearenv ();
 
+	if (setsid() < 0)
+	    /* should never happen */
+	    gdm_error (_("%s: setsid() failed: %s!"),
+	    		"session_child_run", strerror(errno));
+
 	/* Prepare user session */
 	gnome_setenv ("XAUTHORITY", d->userauth, TRUE);
 	gnome_setenv ("DISPLAY", d->name, TRUE);
@@ -2050,10 +2060,6 @@
 		language = unaliaslang (language);
 	}
 
-	/* Set locale */
-	gnome_setenv ("LANG", language, TRUE);
-	gnome_setenv ("GDM_LANG", language, TRUE);
-    
 	setpgid (0, 0);
 	
 	umask (022);
@@ -2069,10 +2075,35 @@
 	 * not to leave the egid around */
 	setegid (pwent->pw_gid);
 
+#ifdef HAVE_LOGINCAP
+	if (setusercontext (NULL, pwent, pwent->pw_uid,
+	    		    LOGIN_SETLOGIN | LOGIN_SETPATH |
+			    LOGIN_SETPRIORITY | LOGIN_SETRESOURCES |
+			    LOGIN_SETUMASK | LOGIN_SETUSER) < 0)
+	    	gdm_child_exit (DISPLAY_REMANAGE,
+				_("%s: setusercontext() failed for %s. "
+				  "Aborting."), "gdm_slave_session_start",
+				login);
+	/* A different language was selected, or taken from the saved
+	 * prefs of the user */
+	if ( ! def_language) {
+	    gnome_setenv ("LANG", language, TRUE);
+	    gnome_setenv ("GDM_LANG", language, TRUE);
+	} else {
+	    /* setusercontext sets up user languages */
+	    gnome_setenv ("GDM_LANG", g_getenv ("LANG"), TRUE);
+	}
+#else
+
 	if (setuid (pwent->pw_uid) < 0) 
 		gdm_child_exit (DISPLAY_REMANAGE,
 				_("gdm_slave_session_start: Could not become %s. Aborting."), login);
 	
+	/* Set locale */
+	gnome_setenv ("LANG", language, TRUE);
+	gnome_setenv ("GDM_LANG", language, TRUE);
+#endif
+
 	chdir (home_dir);
 
 	/* anality, make sure nothing is in memory for gnome_config
@@ -2259,6 +2290,7 @@
     char *gnome_session = NULL;
     gboolean savesess = FALSE, savelang = FALSE, savegnomesess = FALSE;
     gboolean usrcfgok = FALSE, sessoptok = FALSE, authok = FALSE;
+    gboolean def_language = FALSE;
     const char *home_dir = NULL;
     gboolean home_dir_ok = FALSE;
     pid_t pid;
@@ -2392,12 +2424,13 @@
 		    language = g_strdup (lang);
 	    else
 		    language = g_strdup (GdmDefaultLocale);
-	    savelang = TRUE;
 
 	    if (ve_string_empty (language)) {
 		    g_free (language);
 		    language = g_strdup ("C");
 	    }
+
+	    def_language = TRUE;
     }
 
     /* save this session as the users session */
@@ -2499,6 +2532,7 @@
 			   session,
 			   save_session,
 			   language,
+			   def_language,
 			   gnome_session,
 			   usrcfgok,
 			   savesess,
