--- src/pty.c.orig	Sat Apr 12 00:47:10 2003
+++ src/pty.c	Sat Apr 12 00:47:34 2003
@@ -45,6 +45,7 @@
 #include "pty.h"
 
 #ifdef VTE_USE_GNOME_PTY_HELPER
+#include "../gnome-pty-helper/config.h"
 #include "../gnome-pty-helper/gnome-pty.h"
 #endif
 
