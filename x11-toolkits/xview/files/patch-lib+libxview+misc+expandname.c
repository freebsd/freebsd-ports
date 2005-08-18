--- lib/libxview/misc/expandname.c.orig	Thu Aug 18 08:06:28 2005
+++ lib/libxview/misc/expandname.c	Thu Aug 18 08:23:13 2005
@@ -23,14 +23,6 @@
 #include <string.h>
 #include <sgtty.h>
 
-#ifdef sparc
-#ifdef SVR4
-#include <unistd.h>
-#else
-#include <vfork.h>
-#endif
-#endif
-
 #ifdef SVR4
 #include <sys/signal.h>
 #endif
@@ -120,7 +112,9 @@
     }
     (void) close(pivec[0]);
 #ifndef SVR4
+#if !(defined(BSD) && (BSD >= 199103))
     while (wait((union wait *) & status) != pid);
+#endif
 #else
     while (wait( & status) != pid);
 #endif
