--- epplets/Emix.c.orig	Sat Apr  1 06:56:17 2006
+++ epplets/Emix.c	Sat Jun  3 19:44:51 2006
@@ -7,11 +7,16 @@
 #include "epplet.h"
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#ifdef __FreeBSD__
+#include <config.h>
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
 
