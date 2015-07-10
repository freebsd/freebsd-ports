--- utils/textclient.c.orig	2014-11-05 00:08:06 UTC
+++ utils/textclient.c
@@ -50,6 +50,9 @@
 # ifdef HAVE_UTIL_H
 #  include <util.h>
 # endif
+# ifdef HAVE_LIBUTIL_H
+#  include <libutil.h>
+# endif
 #endif /* HAVE_FORKPTY */
 
 #undef DEBUG
