--- libptytty/src/logging.C.orig	2011-12-03 09:58:20.000000000 +0100
+++ libptytty/src/logging.C	2011-12-22 21:20:55.000000000 +0100
@@ -264,7 +264,8 @@
   // posix says that ut_line is not meaningful for DEAD_PROCESS
   // records, but most implementations of last use ut_line to
   // associate records in wtmp file
-  strncpy (utx->ut_line, line, sizeof (utx->ut_line));
+  if(line)
+  	strncpy (utx->ut_line, line, sizeof (utx->ut_line));
   fill_id (utx->ut_id, line, sizeof (utx->ut_id));
   utx->ut_pid = pid;
   utx->ut_type = login ? USER_PROCESS : DEAD_PROCESS;
