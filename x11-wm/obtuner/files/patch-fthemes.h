--- fthemes.h.orig	Wed Sep 14 08:53:37 2005
+++ fthemes.h	Mon May 22 12:21:54 2006
@@ -7,6 +7,11 @@
 #include "rc.h"
 #include <gtk/gtk.h>
 
+#include <sys/types.h>
+#include <sys/time.h>
+#include <unistd.h>
+#include <sys/select.h>
+
 namespace Themes {
     GtkWidget *face(Rc &rc);
 };
