--- parse.c.orig	Thu Jun  4 00:41:45 1998
+++ parse.c	Fri Dec 10 00:58:28 1999
@@ -1376,7 +1376,7 @@
 		dup2(fids[1], 1);	/* stdout = pipe to parent */
 		/* get_defs("m4", dpy, display_name) */
 		tmp_file = m4_defs(dpy, display_name);
-		execlp("m4", "m4", "-s", tmp_file, "-", NULL); 
+		execlp("m4", "m4", tmp_file, "-", NULL); 
 		/* If we get here we are screwed... */
 		perror("Can't execlp() m4");
 		exit(124);
