
$FreeBSD$

--- execute.c	2001/08/20 09:08:11	1.1
+++ execute.c	2001/08/20 09:09:29
@@ -157,13 +157,13 @@
 	pid = fork ();
 	if (pid == 0)
 	{
-		if (setuid (pw->pw_gid))
+		if (setgid (pw->pw_gid))
 		{
 			fprintf (stderr, "unable to set group id\n");
 		}
-		if (setgid (pw->pw_uid))
+		if (setuid (pw->pw_uid))
 		{
-			fprintf (stderr, "unable to set group id\n");
+			fprintf (stderr, "unable to set user id\n");
 		}
 		setenv ("HOME", pw->pw_dir, 1);
 		setenv ("USER", pw->pw_name, 1);
