--- lib/libxview/notify/ndet_read.c.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/ndet_read.c	2012-02-02 21:11:37.972925839 -0800
@@ -15,6 +15,7 @@
  * not already in the middle of it.
  */
 
+#include <sys/param.h>
 #include <xview_private/ntfy.h>
 #include <xview_private/ndet.h>
 #include <xview_private/ndis.h>	/* For ndis_client == NTFY_CLIENT_NULL check */
@@ -29,11 +30,16 @@
 
 static Notify_client ndet_read_nclient = (Notify_client) & ndet_read_done;
 
+#if !(defined(BSD) && (BSD >= 199103))
 extern int
 ndet_read(fd, buf, nbytes)
     register int    fd;
     char           *buf;
     int             nbytes;
+#else
+extern int
+ndet_read(int fd, void *buf, size_t nbytes)
+#endif
 {
     int             ndelay;
     Notify_error    return_code;
