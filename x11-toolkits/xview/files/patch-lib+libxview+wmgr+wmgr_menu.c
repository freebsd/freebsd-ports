--- lib/libxview/wmgr/wmgr_menu.c.orig	Tue Jun 29 07:17:24 1993
+++ lib/libxview/wmgr/wmgr_menu.c	Fri Aug 19 15:57:04 2005
@@ -14,13 +14,6 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
-#ifdef sparc
-#ifdef SVR4
-#include <unistd.h>
-#else
-#include <vfork.h>
-#endif SVR4
-#endif
 
 #include <xview/frame.h>
 #include <xview/wmgr.h>
