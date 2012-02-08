--- lib/libxview/notify/notify.h.orig	2005-03-28 06:41:00.000000000 -0800
+++ lib/libxview/notify/notify.h	2012-02-02 21:25:57.386812073 -0800
@@ -26,9 +26,11 @@
 #if !defined(__linux__) && !defined(__CYGWIN__)
 # ifdef SYSV_WAIT
 #  include <sys/rusage.h>
+# elif (__FreeBSD__>=4)
+#  define SYSV_WAIT
 # endif 
 #endif
-#ifdef SYSV_UCONTEXT
+#if defined(SYSV_UCONTEXT) || (__FreeBSD__>=4)
 # include <sys/ucontext.h>
 #else
 typedef int ucontext_t;
