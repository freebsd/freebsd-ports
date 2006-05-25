--- lib/libxview/win/win_cntral.c.orig	2006-01-04 10:38:51.000000000 +0000
+++ lib/libxview/win/win_cntral.c
@@ -25,7 +25,6 @@ static char     sccsid[] = "@(#)win_cntr
 
 static Notify_error win_send();
 
-extern int      errno;
 extern Event    xv_last_event;
 
 void            notify_perror();
