--- ./lib/libxview/misc/getlogindr.c.orig	Tue Jun 29 07:16:30 1993
+++ ./lib/libxview/misc/getlogindr.c	Sat Apr  1 18:25:25 2000
@@ -17,6 +17,7 @@ static char     sccsid[] = "@(#)getlogin
 
 #include <stdio.h>
 #include <pwd.h>
+#include <sys/param.h>
 #include <xview_private/i18n_impl.h>
 #include <xview/xv_error.h>
 
