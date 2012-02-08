--- lib/libxview/base/base.h.orig	2005-03-28 06:41:49.000000000 -0800
+++ lib/libxview/base/base.h	2012-02-02 16:19:48.679145715 -0800
@@ -6,10 +6,15 @@
  *	file for terms of the license.
  */
 
+#include <sys/param.h>
 #ifndef xview_base_DEFINED
 #define xview_base_DEFINED
 #include <string.h>
+#ifdef __STDC__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #include <xview/xv_c_types.h>
 
@@ -54,10 +59,12 @@
  * non-SVR4 systems.
  */
 #if !defined(SUNOS41) && !defined(__linux__) && !defined(__CYGWIN__)
+#if !(defined(BSD) && (BSD >= 199103))
 #define XV_OS_SVR4
-#define XV_USE_TTCOMPAT
 #define SYSV_WAIT 
 #define SYSV_UCONTEXT 
+#endif
+#define XV_USE_TTCOMPAT
 #define XV_USE_XVFCNTL 
 #elif defined(__linux__)
 #define XV_OS_SVR4
