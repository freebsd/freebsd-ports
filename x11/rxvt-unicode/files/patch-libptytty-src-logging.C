--- libptytty/src/logging.C.orig	2011-05-30 22:59:42.000000000 +0200
+++ libptytty/src/logging.C	2011-10-05 11:12:04.370185467 +0200
@@ -223,7 +223,8 @@
   // records, but most implementations of last use ut_line to
   // associate records in wtmp file
   strncpy (utx->ut_line, line, sizeof (utx->ut_line));
-  strncpy (utx->ut_id, id, sizeof (utx->ut_id));
+  if(id)
+  	strncpy (utx->ut_id, id, sizeof (utx->ut_id));
   utx->ut_pid = pid;
   utx->ut_type = login ? USER_PROCESS : DEAD_PROCESS;
   utx->ut_tv.tv_sec = time (NULL);
@@ -284,11 +285,19 @@
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
@@ -363,11 +372,19 @@
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
