--- libgnome-desktop/gnome-desktop-thumbnail-script.c.orig	2026-02-09 00:58:33 UTC
+++ libgnome-desktop/gnome-desktop-thumbnail-script.c
@@ -31,7 +31,6 @@
 #include <glib/gstdio.h>
 #include <string.h>
 #include <stdlib.h>
-#include <sys/personality.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 
@@ -40,6 +39,7 @@
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <sys/utsname.h>
+#include <sys/personality.h>
 #include <seccomp.h>
 #endif
 
