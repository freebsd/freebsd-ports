--- src/nvidia_ctl.c.old	Sun Feb 22 13:05:46 2004
+++ src/nvidia_ctl.c	Sun Feb 22 13:07:25 2004
@@ -43,7 +43,12 @@
     .d_ioctl =     nvidia_ctl_ioctl,
     .d_poll =      nvidia_ctl_poll,
     .d_name =      "nvidiactl",
+#if __FreeBSD_version < 502103
     .d_maj =       CDEV_MAJOR,
     .d_flags =     D_TRACKCLOSE
+#else
+    .d_version =   D_VERSION, 
+    .d_flags =     D_NEEDGIANT|D_TRACKCLOSE
+#endif 
 #endif
 };
