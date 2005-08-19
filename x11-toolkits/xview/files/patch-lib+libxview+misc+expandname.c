--- lib/libxview/misc/expandname.c.orig	Tue Jun 29 07:16:30 1993
+++ lib/libxview/misc/expandname.c	Fri Aug 19 15:53:44 2005
@@ -23,14 +23,6 @@
 #include <string.h>
 #include <sgtty.h>
 
-#ifdef sparc
-#ifdef SVR4
-#include <unistd.h>
-#else
-#include <vfork.h>
-#endif SVR4
-#endif
-
 #ifdef SVR4
 #include <sys/signal.h>
 #endif SVR4
@@ -120,7 +112,9 @@
     }
     (void) close(pivec[0]);
 #ifndef SVR4
+#if !(defined(BSD) && (BSD >= 199103))
     while (wait((union wait *) & status) != pid);
+#endif
 #else SVR4
     while (wait( & status) != pid);
 #endif SVR4
