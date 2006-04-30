--- gnome-session/gsm-xrandr.c.orig	Mon Apr 17 17:59:38 2006
+++ gnome-session/gsm-xrandr.c	Mon Apr 17 17:59:50 2006
@@ -3,6 +3,7 @@
 #include <gconf/gconf-client.h>
 
 #include "gsm-xrandr.h"
+#include "util.h"
 
 #ifdef HAVE_RANDR
 #include <stdio.h>
