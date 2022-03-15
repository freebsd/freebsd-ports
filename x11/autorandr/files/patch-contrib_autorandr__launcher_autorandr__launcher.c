--- contrib/autorandr_launcher/autorandr_launcher.c.orig	2022-03-15 15:02:37 UTC
+++ contrib/autorandr_launcher/autorandr_launcher.c
@@ -38,7 +38,7 @@ static int ar_launch()
 	pid_t pid = fork();
 	if (pid == 0) {
 		static char *argv[] =
-		    { "/usr/bin/autorandr", "--change", "--default", "default", NULL };
+		    { "%%PREFIX%%/bin/autorandr", "--change", "--default", "default", NULL };
 		execve(argv[0], argv, environ);
 		exit(127);
 	} else {
