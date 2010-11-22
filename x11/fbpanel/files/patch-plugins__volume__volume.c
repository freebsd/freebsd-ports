--- ./plugins/volume/volume.c.orig	2010-05-02 02:13:47.000000000 -0700
+++ ./plugins/volume/volume.c	2010-11-17 11:06:07.000000000 -0800
@@ -11,6 +11,10 @@
 #include <fcntl.h>
 #if defined __linux__
 #include <linux/soundcard.h>
+#else
+#if defined __FreeBSD__
+#include <sys/soundcard.h>
+#endif
 #endif
 
 //#define DEBUGPRN
