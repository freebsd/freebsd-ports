--- lib/libxview/notify/notify.h.orig	Thu Oct 16 16:58:37 2003
+++ lib/libxview/notify/notify.h	Thu Oct 16 17:43:40 2003
@@ -24,8 +24,10 @@
 #include <xview/base.h>
 #ifdef SYSV_WAIT
 #include <sys/rusage.h>
+#elif (__FreeBSD__>=4)
+#define SYSV_WAIT 
 #endif 
-#ifdef SYSV_UCONTEXT
+#if defined(SYSV_UCONTEXT) || (__FreeBSD__>=4)
 #include <sys/ucontext.h>
 #endif 
 
