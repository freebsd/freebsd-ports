--- ./kdm/backend/error.c.orig	Sun Mar 24 12:31:09 2002
+++ ./kdm/backend/error.c	Thu Apr 18 20:53:44 2002
@@ -43,6 +43,8 @@
 #include "dm.h"
 #include "dm_error.h"
 
+#include <sys/stat.h>
+#include <unistd.h>
 #include <stdio.h>
 
 #define PRINT_QUOTES
@@ -91,6 +93,10 @@
 void
 InitErrorLog (const char *errorLogFile)
 {
+    int fd;
+    struct stat st;
+    char buf[128];
+
 #ifdef USE_SYSLOG
 # ifdef USE_PAM
     ReInitErrorLog ();
@@ -101,15 +107,33 @@
     /* We do this independently of using syslog, as we cannot redirect
      * the output of external programs to syslog.
      */
-    if (isatty (2)) {
-	char buf[100];
+    if (errorLogFile
+	|| fstat (1, &st) ||
+#ifndef X_NOT_POSIX
+	!(S_ISREG(st.st_mode) || S_ISFIFO(st.st_mode))
+#else
+	!(st.st_mode & (S_IFREG | S_IFIFO))
+#endif
+	|| fstat (2, &st) ||
+#ifndef X_NOT_POSIX
+	!(S_ISREG(st.st_mode) || S_ISFIFO(st.st_mode)))
+#else
+	!(st.st_mode & (S_IFREG | S_IFIFO)))
+#endif
+    {
 	if (!errorLogFile) {
 	    sprintf (buf, "/var/log/%s.log", prog);
 	    errorLogFile = buf;
 	}
-	if (!freopen (errorLogFile, "a", stderr))
+	if ((fd = open (errorLogFile, O_CREAT | O_APPEND | O_WRONLY, 0666)) < 0)
 	    LogError ("Cannot open log file %s\n", errorLogFile);
+	else {
+	    if (fd != 1) {
+		dup2 (fd, 1);
+		close (fd);
+	    }
+	    dup2 (1, 2);
+	}
     }
-    dup2 (2, 1);
 }
 
