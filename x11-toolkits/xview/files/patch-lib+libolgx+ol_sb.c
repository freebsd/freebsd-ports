--- lib/libolgx/ol_sb.c.orig	Mon Sep 29 00:02:40 2003
+++ lib/libolgx/ol_sb.c	Mon Sep 29 00:02:39 2003
@@ -11,7 +11,12 @@
  */
 
 #include <stdio.h>
+#include <sys/param.h>
+#ifdef __STDC__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include "olgx_impl.h"
