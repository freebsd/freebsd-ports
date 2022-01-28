--- daemon/gdm-session-worker-job.c.orig	2022-01-12 14:15:56 UTC
+++ daemon/gdm-session-worker-job.c
@@ -36,7 +36,9 @@
 #include <sys/prctl.h>
 #endif
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-daemon.h>
+#endif
 
 #ifdef ENABLE_SYSTEMD_JOURNAL
 #include <systemd/sd-journal.h>
