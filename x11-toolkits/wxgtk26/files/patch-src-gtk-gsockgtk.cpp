--- src/gtk//gsockgtk.cpp.orig	2007-03-20 16:50:07.000000000 +0100
+++ src/gtk/gsockgtk.cpp	2009-09-18 14:46:47.000000000 +0200
@@ -14,8 +14,13 @@
 #include <stdlib.h>
 #include <stdio.h>
 
+// newer versions of glib define its own GSocket but we unfortunately use this
+// name in our own (semi-)public header and so can't change it -- rename glib
+// one instead
+#define GSocket GlibGSocket
 #include <gdk/gdk.h>
 #include <glib.h>
+#undef GSocket
 
 #include "wx/gsocket.h"
 #include "wx/unix/gsockunx.h"
