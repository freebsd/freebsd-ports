--- xconsole.c.orig	2013-01-16 00:15:23.910443192 +0100
+++ xconsole.c	2013-01-16 00:20:52.830442361 +0100
@@ -69,6 +69,9 @@
 # ifdef HAVE_UTIL_H
 #  include <util.h>
 # endif
+# ifdef HAVE_LIBUTIL_H
+#  include <libutil.h>
+# endif
 # ifdef HAVE_PTY_H
 #  include <pty.h>
 # endif
