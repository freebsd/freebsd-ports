--- execute.c.orig	Thu Oct 18 13:56:26 2001
+++ execute.c	Thu Jan 10 13:48:12 2002
@@ -161,13 +161,13 @@
 	pid = fork ();
 	if (pid == 0)
 	{
-		if (setuid (pw->pw_gid))
+		if (setgid (pw->pw_gid))
 		{
 //			fprintf (stderr, "unable to set group id\n");
 			SMRunAttentionPanel (wm_screen, LaunchPanel->window,
           "Command Execution", "Unable to set group ID.", NULL, NULL, "Ok");
 		}
-		if (setgid (pw->pw_uid))
+		if (setuid (pw->pw_uid))
 		{
 //			fprintf (stderr, "unable to set user id\n");
 			SMRunAttentionPanel (wm_screen, LaunchPanel->window,
