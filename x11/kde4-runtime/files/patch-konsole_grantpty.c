--- konsole/src/konsole_grantpty.c.orig	Sat Jun 12 07:13:31 1999
+++ konsole/src/konsole_grantpty.c	Fri Dec  8 11:54:43 2000
@@ -31,13 +31,15 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <unistd.h>
+#include <dirent.h>
+#include <paths.h>
 
 #define PTY_FILENO 3    /* keep in sync with grantpty */
 #define TTY_GROUP "tty"
 
 int main (int argc, char *argv[])
 {
-  char*         pty;
+  char*         pty = NULL;
   struct stat   st;
   struct group* p;
   gid_t         gid;
@@ -81,6 +83,7 @@
 
   /* get slave pty name from master pty file handle in PTY_FILENO *********/
 
+#if 0
   /* Check that PTY_FILENO is a valid master pseudo terminal.  */
   pty = ttyname(PTY_FILENO);          /* posix */
   if (pty == NULL)
@@ -89,6 +92,42 @@
     return 1; /* FAIL */
   }
   close(PTY_FILENO);
+#else
+	/* The trouble with the ifdef'd-out portion above is that ttyname()
+	** does not work correctly when not passed a valid tty, but a pseudotty
+	** instead. All we're doing here is finding out what the name of
+	** the associated pty is without having to pass it in on the command line.
+	** Nothing complex.
+	*/
+	{
+		struct stat sb;
+		struct stat dsb;
+		struct dirent *dirp;
+		static char buf[sizeof(_PATH_DEV) + MAXNAMLEN] = _PATH_DEV;
+		DIR *dp;
+		
+		pty = NULL;
+		
+		if (fstat(PTY_FILENO, &sb))
+			return 1; /* FAIL */
+		if ((dp = opendir(_PATH_DEV)) == NULL)
+			return 1; /* FAIL */
+		
+		while ((dirp = readdir(dp))) {
+			if (dirp->d_fileno != sb.st_ino)
+				continue;
+			bcopy(dirp->d_name, buf + sizeof(_PATH_DEV) - 1, dirp->d_namlen+1);
+			/*fprintf(stderr, "looking at %s\n", buf);*/
+			if (stat(buf, &dsb) || sb.st_dev != dsb.st_dev || sb.st_ino != dsb.st_ino)
+				continue;
+			pty = buf;
+		}
+		closedir(dp);
+		if (pty == NULL)
+			return 1; /* FAIL */
+	}
+	/*fprintf(stderr, "successful at finding %s\n", pty);*/
+#endif
 
   /* matches /dev/pty?? */
   if (strlen(pty) < 8 || strncmp(pty,"/dev/pty",8))
@@ -120,6 +159,8 @@
     fprintf(stderr,"%s: cannot chmod %s.\n",argv[0],tty); perror("Reason");
     return 1; /* FAIL */
   }
+	
+	/*fprintf(stderr, "made it here\n");*/
 
   return 0; /* OK */
 }
