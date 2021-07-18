--- libptytty/src/ptytty.C.orig	2015-05-11 22:24:03 UTC
+++ libptytty/src/ptytty.C
@@ -56,6 +56,11 @@
 # define O_NOCTTY 0
 #endif
 
+/* We need __FreeBSD_version */
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
+
 /////////////////////////////////////////////////////////////////////////////
 
 /* ------------------------------------------------------------------------- *
@@ -395,7 +400,17 @@ ptytty_unix::get ()
   int fd_stdin = dup (STDIN_FILENO);
   dup2 (tty, STDIN_FILENO);
 
+/*
+ * FreeBSD base@r202219 phased out utmp and moved to utmpx.
+ * ttyslot() was eliminated slightly after this, in r202274,
+ * but __FreeBSD_version wasn't bumped then.  Such discrepance
+ * should be harmless since we will lose at most an utmp record.
+ */
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+  utmp_pos = -1;
+#else
   utmp_pos = ttyslot ();
+#endif
 
   dup2 (fd_stdin, STDIN_FILENO);
   close (fd_stdin);
