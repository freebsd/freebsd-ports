--- lib/libxview/notify/ntfy.h.orig	Thu Oct 16 21:09:40 2003
+++ lib/libxview/notify/ntfy.h	Thu Oct 16 23:43:09 2003
@@ -22,6 +22,10 @@
 #include <sys/rusage.h>
 #endif
 #include <sys/resource.h>
+#if (defined(BSD) && (BSD >= 199103))
+#include <sys/wait.h>
+#include <sys/signal.h>
+#endif
 #include <xview/notify.h>
 
 /*
@@ -149,7 +153,7 @@
  */
 typedef	struct ntfy_wait3_data {
 	int	pid;			/* Process waiting for */
-#ifndef SVR4
+#if (!defined(BSD4_4) && !defined(SVR4))
 	union	wait status;		/* Return value from wait3 */
 #else
 	int 	status;		/* Return value from wait3 */
@@ -188,7 +192,12 @@
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
 
 /*
@@ -456,7 +465,7 @@
 /*
  * Debugging aids.
  */
-#define	NTFY_DEBUG	1
+#define	NTFY_DEBUG	0
 /*
  * Ntfy_set_errno is for setting notify_errno when there is really something
  * wrong.  An error message is displayed with notifier code has been compiled
