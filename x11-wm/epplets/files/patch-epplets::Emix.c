--- epplets/Emix.c.orig	Wed Sep 13 08:24:16 2000
+++ epplets/Emix.c	Thu Dec 18 19:20:45 2003
@@ -6,11 +6,17 @@
 
 #include "epplet.h"
 #include <sys/ioctl.h>
-#ifdef __FreeBSD__
+#include <config.h>
+
+#ifdef HAVE_LINUX_SOUNDCARD_H
+#include <linux/soundcard.h>
+#elif HAVE_MACHINE_SOUNDCARD_H
 #include <machine/soundcard.h>
-#else
+#elif HAVE_SYS_SOUNDCARD_H
 #include <sys/soundcard.h>
-#endif
+#else
+#error No soundcard defenition!
+#endif /* SOUNDCARD_H */
 
 Epplet_gadget vs_master, vs_pcm, vs_lin, vs_cda, b_close, b_help;
 
