--- arch/unix/Mutex.hh.orig	Sun Jan  5 00:53:45 2003
+++ arch/unix/Mutex.hh	Sat Jul 12 16:40:21 2003
@@ -23,6 +23,11 @@
 
 #include <pthread.h>
 
+// define this to something freebsd knows
+#ifdef __FreeBSD__
+#define PTHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE
+#endif
+
 /*!
  * A Mutex class.
  */
