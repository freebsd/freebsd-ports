--- olwm.c.orig	Thu Jan 13 15:36:12 1994
+++ olwm.c	Mon Oct 19 14:08:54 1998
@@ -677,9 +677,15 @@
         pid_t pid;
         int status;
 #else
+#ifdef BSD
+	int oldmask;
+	int pid;
+	int status;
+#else
 	int oldmask;
 	int pid;
 	union wait status;
+#endif
 #endif
 
 	if (!deadChildren)
