--- lib/libxview/notify/ndetselect.c.orig	2006-01-04 11:53:02.000000000 +0000
+++ lib/libxview/notify/ndetselect.c
@@ -28,7 +28,6 @@ static int      ndet_select_nfds, ndet_s
 
 static Notify_client ndet_select_nclient = (Notify_client) & ndet_select_ibits;
 
-extern          errno;
 extern int      notify_exclude_fd;
 
 extern int
