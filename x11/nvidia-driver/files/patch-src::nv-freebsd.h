--- src/nv-freebsd.h.orig	Wed Feb 25 18:55:35 2004
+++ src/nv-freebsd.h	Wed Feb 25 18:55:49 2004
@@ -217,7 +217,9 @@
 } nvidia_softc_t;
 
 
+#if __FreeBSD_version < 502103
 #define CDEV_MAJOR      180
+#endif
 #define CDEV_CTL_MINOR  255
 
 extern devclass_t nvidia_devclass;
