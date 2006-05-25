--- lib/libxview/notify/ndet_wait.c.orig	2006-01-04 11:52:12.000000000 +0000
+++ lib/libxview/notify/ndet_wait.c
@@ -18,8 +18,6 @@ static char     sccsid[] = "@(#)ndet_wai
 #include <xview_private/ndet.h>
 #include <errno.h>
 
-extern          errno;
-
 pkg_private int
 ndet_check_pid(pid)
     int             pid;
