--- konsole/konsole/konsole_grantpty.c	2 Sep 2002 01:09:24 -0000	1.7
+++ konsole/konsole/konsole_grantpty.c	24 Aug 2003 21:44:01 -0000
@@ -40,7 +40,9 @@
 #  include <dirent.h>
 #endif

-#define PTY_FILENO 3    /* keep in sync with grantpty */
+#define DEFAULT_PTY_FILENO 3 /* keep in sync with TEPty.cpp */
+int PTY_FILENO = DEFAULT_PTY_FILENO;
+
 #define TTY_GROUP "tty"

 int main (int argc, char *argv[])
@@ -52,11 +54,13 @@ int main (int argc, char *argv[])
   uid_t         uid;
   mode_t        mod;
   char*         tty;
+  int           command_fd; /* which fd to use? */

   /* check preconditions **************************************************/
-  if (argc != 2 || (strcmp(argv[1],"--grant") && strcmp(argv[1],"--revoke")))
+  if (( (argc != 3) && (argc != 2) /* optional third arg */ ) ||
+    (strcmp(argv[1],"--grant") && strcmp(argv[1],"--revoke")))
   {
-    printf("usage: %s (--grant|--revoke)\n",argv[0]);
+    printf("usage: %s (--grant|--revoke) [fd]\n",argv[0]);
     printf("%s is a helper for\n",argv[0]);
     printf("konsole and not intented to\n");
     printf("be called from the command\n");
@@ -83,6 +87,22 @@ int main (int argc, char *argv[])
     uid = 0;        /* root */
     mod = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
   }
+
+  command_fd = DEFAULT_PTY_FILENO;
+  if (argv[2])
+  {
+    command_fd = atoi(argv[2]);
+  }
+  if (command_fd > 2) /* must be out of stdin,stdout,stderr range */
+  {
+    PTY_FILENO=command_fd;
+  }
+  else
+  {
+    fprintf(stderr,"%s: Bad command fd (seems to be %d)\n",argv[0],command_fd);
+    return 1;
+  }
+  
   /* Get the group ID of the special `tty' group.  */
   p = getgrnam(TTY_GROUP);            /* posix */
   gid = p ? p->gr_gid : getgid ();    /* posix */
@@ -117,6 +137,9 @@ int main (int argc, char *argv[])
           if (dirp->d_fileno != dsb.st_ino)
             continue;
 	  {
+	  /* Else this is the right device file .. any possible memory
+	  ** leak here because two files match is unimportant?
+	  */
 	  int pdlen = strlen(_PATH_DEV), namelen = strlen(dirp->d_name);
 	  pty = malloc(pdlen + namelen + 1);
 	  if (pty) {