--- utils/textclient.c.orig	2013-09-02 12:43:01.271738814 +0200
+++ utils/textclient.c	2013-09-02 12:43:25.014748042 +0200
@@ -50,6 +50,9 @@
 # ifdef HAVE_UTIL_H
 #  include <util.h>
 # endif
+# ifdef HAVE_LIBUTIL_H
+#  include <libutil.h>
+# endif
 #endif /* HAVE_FORKPTY */
 
 /*#define DEBUG*/
