--- lib/libxview/wmgr/wmgr_menu.c.orig	Thu Aug 18 08:42:34 2005
+++ lib/libxview/wmgr/wmgr_menu.c	Thu Aug 18 08:42:52 2005
@@ -14,13 +14,6 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
-#ifdef sparc
-#ifdef SVR4
-#include <unistd.h>
-#else
-#include <vfork.h>
-#endif
-#endif
 
 #include <xview/frame.h>
 #include <xview/wmgr.h>
