--- clients/olwm/olwm.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/olwm.c	2012-02-02 15:22:35.676398718 -0800
@@ -23,6 +23,10 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 
+#ifndef MAXPID
+#define MAXPID 30000
+#endif
+
 #include <X11/Xos.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
@@ -637,6 +641,10 @@
 #if defined SYSV || defined __CYGWIN__
         pid_t pid;
         int status;
+#elif (defined(BSD) && (BSD >= 199103))
+	pid_t pid;
+	int status;
+	int oldmask;
 #else
 	int oldmask;
 	int pid;
