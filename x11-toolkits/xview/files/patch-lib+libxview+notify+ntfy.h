--- lib/libxview/notify/ntfy.h.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/ntfy.h	2012-02-02 22:53:44.551883626 -0800
@@ -35,6 +35,10 @@
 #include <sys/rusage.h>
 #endif
 #include <sys/resource.h>
+#if (defined(BSD) && (BSD >= 199103))
+#include <sys/wait.h>
+#include <sys/signal.h>
+#endif
 #include <xview/notify.h>
 
 /*
@@ -167,7 +171,7 @@
  */
 typedef	struct ntfy_wait3_data {
 	int	pid;			/* Process waiting for */
-#if !defined(SVR4) && !(defined(__linux__) || defined(__CYGWIN__))
+#if !defined(SVR4) && !(defined(__linux__) || defined(__CYGWIN__) || defined(BSD4_4))
 	union	wait status;		/* Return value from wait3 */
 #else /* SVR4 */
 	int 	status;		/* Return value from wait3 */
@@ -210,7 +214,12 @@
 #define sigisempty(s)   (!(((s)->__sigbits[0]) | ((s)->__sigbits[1])   \
                         | ((s)->__sigbits[2]) | ((s)->__sigbits[3])))
 #else
-#define sigisempty(s)   (!(*(s)))
+static int
+sigisempty (sigset_t *s) {
+	sigset_t n;      
+	bzero(&n, sizeof(sigset_t));
+	return (! memcmp(&n, s, sizeof(sigset_t)));
+}
 #endif
 #endif
 
