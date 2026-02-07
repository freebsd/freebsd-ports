--- include/options.h.orig	2007-09-30 18:30:29.000000000 -0300
+++ include/options.h	2008-02-18 23:26:18.000000000 -0300
@@ -39,7 +39,7 @@
   msg_exit,      /* kill a running xautolock             */
   msg_lockNow,   /* tell running xautolock to lock now   */
   msg_unlockNow, /* tell running xautolock to unlock now */
-  msg_restart,   /* tell running xautolock to restart    */
+  msg_restart    /* tell running xautolock to restart    */
 } message;
 
 /*
