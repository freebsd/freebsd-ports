--- libptytty/src/logging.C.orig	2011-05-31 00:59:42.000000000 +0400
+++ libptytty/src/logging.C	2011-09-21 16:19:44.000000000 +0400
@@ -284,11 +284,19 @@
 #endif
 
 #ifdef HAVE_STRUCT_UTMP
+# ifdef HAVE_UTMP_PID
   fill_utmp (ut, true, cmd_pid, ut_id, pty, user, hostname);
+# else
+  fill_utmp (ut, true, cmd_pid, 0, pty, user, hostname);
+# endif
 #endif
 
 #ifdef HAVE_STRUCT_UTMPX
+# ifdef HAVE_UTMP_PID
   fill_utmpx (utx, true, cmd_pid, ut_id, pty, user, hostname);
+# else
+  fill_utmpx (utx, true, cmd_pid, 0, pty, user, hostname);
+# endif
 #endif
 
 #ifdef HAVE_STRUCT_UTMP
@@ -363,11 +371,19 @@
 #endif
 
 #ifdef HAVE_STRUCT_UTMP
+# ifdef HAVE_UTMP_PID
   fill_utmp (ut, false, cmd_pid, ut_id, pty, 0, 0);
+# else
+  fill_utmp (ut, false, cmd_pid, 0, pty, 0, 0);
+# endif
 #endif
 
 #ifdef HAVE_STRUCT_UTMPX
+# ifdef HAVE_UTMP_PID
   fill_utmpx (utx, false, cmd_pid, ut_id, pty, 0, 0);
+# else
+  fill_utmpx (utx, false, cmd_pid, 0, pty, 0, 0);
+# endif
 #endif
 
   /*
