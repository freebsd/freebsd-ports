--- src/nvidia_ctl.c.orig	Wed Oct 30 15:30:58 2002
+++ src/nvidia_ctl.c	Thu Mar  6 01:07:57 2003
@@ -19,6 +19,7 @@
 static d_poll_t  nvidia_ctl_poll;
 
 static struct cdevsw nvidia_ctl_cdevsw = {
+#if __FreeBSD_version < 500000
     /* open    */  nvidia_ctl_open,
     /* close */    nvidia_ctl_close,
     /* read */     noread,
@@ -32,10 +33,17 @@
     /* dump */     nodump,
     /* psize */    nopsize,
     /* flags */    D_TRACKCLOSE,
-#if __FreeBSD_version < 500000
     /* bmaj */     -1,
-#endif
     /* kqfilter */ NULL,
+#else
+    .d_open =      nvidia_ctl_open,
+    .d_close =     nvidia_ctl_close,
+    .d_ioctl =     nvidia_ctl_ioctl,
+    .d_poll =      nvidia_ctl_poll,
+    .d_name =      "nvidiactl",
+    .d_maj =       CDEV_MAJOR,
+    .d_flags =     D_TRACKCLOSE
+#endif
 };
 
 static dev_t          nvidia_ctl_cdev;
