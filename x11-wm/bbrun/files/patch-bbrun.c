--- bbrun.c.orig	Sat Jul 20 13:24:53 2002
+++ bbrun.c	Sat Jul 20 20:31:49 2002
@@ -3,7 +3,11 @@
 #include <string.h>
 #include <getopt.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#else
 #include <linux/types.h>
+#endif
 #include <X11/xpm.h>
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
@@ -20,7 +24,7 @@
 #define ADVANCED_WINDOW_ROWS 3
 #define ADVANCED_WINDOW_COLS 10
 
-#define u32 __u32
+#define u32 u_int32_t
 #define __DEBUG__ 0
 #define VERSION "1.4"
 
