$FreeBSD$

--- util/monolaunch.c.orig	Wed Jul 10 06:38:02 2002
+++ util/monolaunch.c	Sun Jul 14 20:41:16 2002
@@ -20,14 +20,12 @@
 */
 
 #include <stdlib.h>
-#include <getopt.h>
 #include <string.h>
 #include <fcntl.h>
 #include <stdio.h>
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/sysmacros.h>
 #include <signal.h>
 #include <X11/X.h>
 #include <X11/Xlib.h>
