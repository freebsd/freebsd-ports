--- lib/libolgx/ol_init.c.orig	2012-02-03 13:24:25.181587269 -0800
+++ lib/libolgx/ol_init.c	2012-02-03 13:26:13.093464170 -0800
@@ -9,7 +9,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <X11/Xlib.h>
 #include "olgx_impl.h"
 #include "busy.h"
