--- clients/olwm/olwm.c.orig	Tue Apr 22 23:19:15 2003
+++ clients/olwm/olwm.c	Tue Apr 22 23:43:14 2003
@@ -21,7 +21,7 @@
 #include <sys/param.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
-#include <sys/wait.h>
+#include "wait.h"
 
 #include <X11/Xos.h>
 #include <X11/Xlib.h>
--- contrib/examples/notifier/ntfy_pipe.c.orig	Tue Apr 22 23:20:04 2003
+++ contrib/examples/notifier/ntfy_pipe.c	Tue Apr 22 23:20:39 2003
@@ -11,7 +11,7 @@
 #include <signal.h>
 #include <sys/time.h>
 #include <sys/types.h>
-#include <sys/wait.h>
+#include "wait.h"
 #include <sys/resource.h>
 #include <sys/ioctl.h>
 #include <xview/notify.h>
--- lib/libxview/misc/expandname.c.orig	Tue Apr 22 23:21:21 2003
+++ lib/libxview/misc/expandname.c	Tue Apr 22 23:21:39 2003
@@ -18,7 +18,7 @@
 
 #include <sys/param.h>
 #include <sys/stat.h>
-#include <sys/wait.h>
+#include "wait.h"
 #include <stdio.h>
 #include <string.h>
 #include <sgtty.h>
--- lib/libxview/ttysw/tty.c.orig	Tue Apr 22 23:22:10 2003
+++ lib/libxview/ttysw/tty.c	Tue Apr 22 23:22:27 2003
@@ -17,7 +17,7 @@
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/time.h>
-#include <sys/wait.h>
+#include "wait.h"
 #include <pixrect/pixrect.h>
 #include <pixrect/pixfont.h>
 #include <xview_private/i18n_impl.h>
--- lib/libxview/ttysw/termsw.c.orig	Tue Apr 22 23:23:06 2003
+++ lib/libxview/ttysw/termsw.c	Tue Apr 22 23:23:29 2003
@@ -17,7 +17,7 @@
 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/types.h>
-#include <sys/wait.h>
+#include "wait.h"
 #include <xview/sun.h>
 #include <xview/frame.h>
 #include <xview/tty.h>
--- lib/libxview/ttysw/tty_ntfy.c.orig	Tue Apr 22 23:23:54 2003
+++ lib/libxview/ttysw/tty_ntfy.c	Tue Apr 22 23:24:44 2003
@@ -18,7 +18,7 @@
 #include <sys/file.h>
 #include <sys/time.h>
 #include <sys/resource.h>
-#include <sys/wait.h>
+#include "wait.h"
 #include <signal.h>
 #include <stdio.h>
 #include <errno.h>
--- lib/libxview/ttysw/term_ntfy.c.orig	Tue Apr 22 23:25:05 2003
+++ lib/libxview/ttysw/term_ntfy.c	Tue Apr 22 23:25:24 2003
@@ -17,7 +17,7 @@
 #include <sys/file.h>
 #include <sys/time.h>
 #include <sys/resource.h>
-#include <sys/wait.h>
+#include "wait.h"
 #include <signal.h>
 #include <stdio.h>
 #include <ctype.h>
--- lib/libxview/notify/ntfy.h.orig	Tue Apr 22 23:25:54 2003
+++ lib/libxview/notify/ntfy.h	Tue Apr 22 23:26:20 2003
@@ -23,7 +23,7 @@
 #endif
 #include <sys/resource.h>
 #if (defined(BSD) && (BSD >= 199103))
-#include <sys/wait.h>
+#include  "wait.h"
 #include <sys/signal.h>
 #endif
 #include <xview/notify.h>
--- lib/libxview/notify/notify.h.orig	Tue Apr 22 23:26:42 2003
+++ lib/libxview/notify/notify.h	Tue Apr 22 23:36:29 2003
@@ -18,7 +18,7 @@
 
 #include <stdio.h>
 #include <sys/types.h>
-#include <sys/wait.h>
+#include "wait.h"
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <xview/base.h>
