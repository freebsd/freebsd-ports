--- ./lib/libxview/frame/frame_cmd.h.orig	Tue Jun 29 07:16:14 1993
+++ ./lib/libxview/frame/frame_cmd.h	Sat Apr  1 18:25:24 2000
@@ -17,11 +17,16 @@ static char     sccsid[] = "@(#)frame_cm
 #define _frame_cmd_h_already_included
 
 /* standard includes */
+#ifdef NULL
+#undef NULL
+#endif
 #ifndef FILE
 #ifndef SVR4
-#undef NULL
 #endif SVR4
 #include <stdio.h>
+#ifndef NULL
+#define NULL 0
+#endif
 #endif FILE
 #include <sys/time.h>
 #include <xview/notify.h>
