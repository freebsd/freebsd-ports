--- epplets/E-SD.c.orig	2008-01-11 09:53:52.000000000 +0100
+++ epplets/E-SD.c	2008-01-11 09:56:10.000000000 +0100
@@ -586,6 +586,11 @@
       esd_monitor_stream(ESD_BITS16 | ESD_STEREO | ESD_STREAM | ESD_PLAY,
 			 RATE, NULL, "E-SD");
 
+   if(esd.fd < 0) {
+      printf("ERROR: Couldn't open EsounD monitor stream!\n");
+      exit(EXIT_FAILURE);
+   }
+
    fcntl(esd.fd, F_SETFL, O_NONBLOCK);
 
    if (esd_get_standby_mode(esd.fd) == ESM_RUNNING)
