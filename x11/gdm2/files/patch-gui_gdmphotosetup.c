--- gui/gdmphotosetup.c.orig	Mon May  5 21:47:14 2003
+++ gui/gdmphotosetup.c	Mon May  5 21:47:39 2003
@@ -22,6 +22,7 @@
 #include <libgnome/libgnome.h>
 #include <libgnomeui/libgnomeui.h>
 #include <sys/types.h>
+#include <signal.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
