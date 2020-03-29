https://lists.sr.ht/~sircmpwn/public-inbox/patches/10091

--- devmgr.c.orig	2019-09-26 02:48:08 UTC
+++ devmgr.c
@@ -4,6 +4,9 @@
  *
  * NOTICE: Most of this code runs as root.
  */
+#ifdef __FreeBSD__
+#define __BSD_VISIBLE 1
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <libinput.h>
