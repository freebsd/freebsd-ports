--- driver/passwd-pam.c.orig	Sat Jul 12 04:44:38 2003
+++ driver/passwd-pam.c	Thu Feb  5 18:09:45 2004
@@ -183,6 +183,7 @@
   char *user = 0;
   sigset_t set;
   struct timespec timeout;
+  struct timeval tv;
 
   struct passwd *p = getpwuid (getuid ());
   if (!p) return False;
@@ -249,8 +250,9 @@
   timeout.tv_sec = 0;
   timeout.tv_nsec = 1;
   set = block_sigchld();
+  TIMESPEC_TO_TIMEVAL (&tv, &timeout);
   status = pam_authenticate (pamh, 0);
-  sigtimedwait (&set, NULL, &timeout);
+  select (0, NULL, NULL, NULL, &tv);
   unblock_sigchld();
 
   if (verbose_p)
@@ -289,7 +291,7 @@
 
   set = block_sigchld();
   status = pam_authenticate (pamh, 0);
-  sigtimedwait(&set, NULL, &timeout);
+  select (0, NULL, NULL, NULL, &tv);
   unblock_sigchld();
 
   if (verbose_p)
