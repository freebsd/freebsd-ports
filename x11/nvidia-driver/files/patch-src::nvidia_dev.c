--- src/nvidia_dev.c.old	Wed May 28 12:51:52 2003
+++ src/nvidia_dev.c	Sun Feb 22 13:36:25 2004
@@ -45,7 +45,12 @@
     .d_poll =      nvidia_dev_poll,
     .d_mmap =      nvidia_dev_mmap,
     .d_name =      "nvidia",
+#if __FreeBSD_version < 502103
     .d_maj =       CDEV_MAJOR,
     .d_flags =     D_MEM|D_TRACKCLOSE
+#else
+    .d_version =   D_VERSION,
+    .d_flags   =   D_MEM|D_TRACKCLOSE|D_NEEDGIANT
+#endif
 #endif
 };
