--- src/gtk/gsockgtk.c.orig	2003-09-21 13:31:58.000000000 +0200
+++ src/gtk/gsockgtk.c	2009-09-28 13:38:26.000000000 +0200
@@ -13,8 +13,15 @@
 #include <stdlib.h>
 #include <stdio.h>
 
+// newer versions of glib define its own GSocket but we unfortunately use this
+// name in our own (semi-)public header and so can't change it -- rename glib
+// one instead
+#define GSocket GlibGSocket
+#define _GSocket GlibGSocket
 #include <gdk/gdk.h>
 #include <glib.h>
+#undef GSocket
+#undef _GSocket
 
 #include "wx/gsocket.h"
 #include "wx/unix/gsockunx.h"
