--- daemon/slave.c.orig	Sat Jun 11 00:44:02 2005
+++ daemon/slave.c	Sat Jun 11 00:45:58 2005
@@ -4058,14 +4058,6 @@
 	    home_dir = pwent->pw_dir;
     }
 
-    if G_UNLIKELY (setegid (pwent->pw_gid) != 0 ||
-		   seteuid (pwent->pw_uid) != 0) {
-	    gdm_error ("Cannot set effective user/group id");
-	    gdm_verify_cleanup (d);
-	    session_started = FALSE;
-	    return;
-    }
-
     if G_LIKELY (home_dir_ok) {
 	    /* Sanity check on ~user/.dmrc */
 	    usrcfgok = gdm_file_check ("gdm_slave_session_start", pwent->pw_uid,
