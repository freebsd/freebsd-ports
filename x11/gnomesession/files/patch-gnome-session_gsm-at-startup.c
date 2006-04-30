--- gnome-session/gsm-at-startup.c.orig	Mon Apr 17 18:00:38 2006
+++ gnome-session/gsm-at-startup.c	Mon Apr 17 18:00:57 2006
@@ -2,6 +2,7 @@
 #include <string.h>
 
 #include "gsm-at-startup.h"
+#include "util.h"
 
 #include <gdk/gdk.h>
 #include <libgnome/libgnome.h>
