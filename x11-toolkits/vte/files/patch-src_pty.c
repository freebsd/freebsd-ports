--- src/pty.c.orig	Tue Jun  3 15:54:15 2003
+++ src/pty.c	Wed Apr  7 02:55:57 2004
@@ -45,6 +45,7 @@
 #include "pty.h"
 
 #ifdef VTE_USE_GNOME_PTY_HELPER
+#include "../gnome-pty-helper/config.h"
 #include "../gnome-pty-helper/gnome-pty.h"
 #endif
 
@@ -709,6 +710,8 @@
 #ifdef HAVE_GETPT
 	/* Call the system's function for allocating a pty. */
 	fd = getpt();
+#elif defined(HAVE_POSIX_OPENPT)
+	fd = posix_openpt(O_RDWR | O_NOCTTY);
 #else
 	/* Try to allocate a pty by accessing the pty master multiplex. */
 	fd = open("/dev/ptmx", O_RDWR | O_NOCTTY);
