_POSIX_C_SOURCE requires an argument unlike _POSIX_SOURCE

In file included from ../src/gtklock.c:7:
In file included from /usr/local/include/glib-2.0/glib-unix.h:30:
In file included from /usr/include/unistd.h:35:
In file included from /usr/include/sys/types.h:40:
In file included from /usr/include/sys/cdefs.h:504:
/usr/include/sys/_visible.h:73:49: error: invalid token at start of a preprocessor expression
   73 | #if defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE == 1
      |                                                 ^
/usr/include/sys/_visible.h:79:49: error: invalid token at start of a preprocessor expression
   79 | #if defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE == 2
      |                                                 ^
[...]

--- src/gtklock.c.orig	2026-10-27 21:38:57 UTC
+++ src/gtklock.c
@@ -3,7 +3,7 @@
 
 // gtklock application
 
-#define _POSIX_C_SOURCE
+#define _POSIX_SOURCE
 #include <glib-unix.h>
 #include <gtk/gtk.h>
 
