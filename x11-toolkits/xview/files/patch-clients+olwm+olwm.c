--- clients/olwm/olwm.c.orig	Fri Oct 17 18:23:53 2003
+++ clients/olwm/olwm.c	Fri Oct 17 18:48:37 2003
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
@@ -622,9 +626,13 @@
 void
 ReapChildren()
 {
-#ifdef SYSV
+#if defined(SYSV)
         pid_t pid;
         int status;
+#elif (defined(BSD) && (BSD >= 199103))
+	pid_t pid;
+	int status;
+	int oldmask;
 #else
 	int oldmask;
 	int pid;
