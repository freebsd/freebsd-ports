--- fthemes.h.orig	Tue May  9 09:31:44 2006
+++ fthemes.h	Tue May  9 09:31:58 2006
@@ -6,6 +6,7 @@
 #include "value.h"
 #include "rc.h"
 #include <gtk/gtk.h>
+#include <sys/select.h>
 
 namespace Themes {
     GtkWidget *face(Rc &rc);
