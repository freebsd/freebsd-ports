--- src/wmgeneral/misc.c.orig	Fri Jan 23 21:58:35 2004
+++ src/wmgeneral/misc.c	Sat Jan 24 15:16:21 2004
@@ -221,8 +221,8 @@
 	{
 	  args[i] = argv[i];
 	}
-      args[argc] = NULL;
-      execvp (argv[0], args);
+      /* args[argc] = NULL;
+      execvp (argv[0], args); */
       exit (10);
     }
   return pid;
