--- src/ptytty.C.orig	Sat Jul 31 17:05:04 2004
+++ src/ptytty.C	Tue Aug 10 18:16:01 2004
@@ -33,6 +33,11 @@
 #endif
 #endif
 
+#if defined( __FreeBSD__)
+#include <sys/types.h>
+# include <libutil.h>
+#endif
+
 #include <cstdio>
 #ifdef HAVE_STDLIB_H
 # include <cstdlib>
