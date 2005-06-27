--- daemon/slave.c.orig	Fri May  6 17:05:17 2005
+++ daemon/slave.c	Sun Jun 26 15:53:00 2005
@@ -4014,6 +4014,10 @@
 
     }
 
+    /*
+     * Set euid, gid to user before testing for user's $HOME since root
+     * does not always have access to the user's $HOME directory.
+     */
     if G_UNLIKELY (setegid (pwent->pw_gid) != 0 ||
 		   seteuid (pwent->pw_uid) != 0) {
 	    gdm_error ("Cannot set effective user/group id");
@@ -4033,6 +4037,7 @@
 		       "you use a failsafe session."),
 		     ve_sure_string (pwent->pw_dir));
 
+	    /* Set euid, egid to root:gdm to manage user interaction */
             seteuid (0);
             setegid (GdmGroupId);
 
@@ -4051,19 +4056,20 @@
 
 	    g_free (msg);
 
+	    /* Reset euid, egid back to user */
+	    if G_UNLIKELY (setegid (pwent->pw_gid) != 0 ||
+			   seteuid (pwent->pw_uid) != 0) {
+		    gdm_error ("Cannot set effective user/group id");
+		    gdm_verify_cleanup (d);
+		    session_started = FALSE;
+		    return;
+	    }
+
 	    home_dir_ok = FALSE;
 	    home_dir = "/";
     } else {
 	    home_dir_ok = TRUE;
 	    home_dir = pwent->pw_dir;
-    }
-
-    if G_UNLIKELY (setegid (pwent->pw_gid) != 0 ||
-		   seteuid (pwent->pw_uid) != 0) {
-	    gdm_error ("Cannot set effective user/group id");
-	    gdm_verify_cleanup (d);
-	    session_started = FALSE;
-	    return;
     }
 
     if G_LIKELY (home_dir_ok) {
