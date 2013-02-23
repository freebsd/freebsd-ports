--- src/nvidia_linux.c.orig	2012-10-30 13:54:06.000000000 -0400
+++ src/nvidia_linux.c	2013-02-13 19:48:17.000000000 -0500
@@ -21,9 +21,11 @@
 #if defined(NVCPU_X86)
 #include "machine/../linux/linux.h"
 #include "machine/../linux/linux_proto.h"
+#include "machine/../../compat/linux/linux_ioctl.h"
 #elif defined(NVCPU_X86_64)
 #include "machine/../linux32/linux.h"
 #include "machine/../linux32/linux32_proto.h"
+#include "machine/../../compat/linux/linux_ioctl.h"
 #endif
 
 int linux_ioctl_nvidia(d_thread_t *, struct linux_ioctl_args *);
