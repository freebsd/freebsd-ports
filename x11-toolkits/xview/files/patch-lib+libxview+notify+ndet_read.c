--- ./lib/libxview/notify/ndet_read.c.orig	Tue Jun 29 07:18:04 1993
+++ ./lib/libxview/notify/ndet_read.c	Sat Apr  1 18:25:25 2000
@@ -15,6 +15,7 @@ static char     sccsid[] = "@(#)ndet_rea
  * not already in the middle of it.
  */
 
+#include <sys/param.h>
 #include <xview_private/ntfy.h>
 #include <xview_private/ndet.h>
 #include <xview_private/ndis.h>	/* For ndis_client == NTFY_CLIENT_NULL check */
@@ -29,11 +30,16 @@ static int      ndet_read_done;
 
 static Notify_client ndet_read_nclient = (Notify_client) & ndet_read_done;
 
+#if !(defined(BSD) && (BSD >= 199103))
 extern int
 read(fd, buf, nbytes)
     register int    fd;
     char           *buf;
     int             nbytes;
+#else
+extern int
+read(int fd, void *buf, size_t nbytes)
+#endif
 {
     int             ndelay;
     Notify_error    return_code;
