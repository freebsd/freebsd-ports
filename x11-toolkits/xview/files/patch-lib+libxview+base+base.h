--- lib/libxview/base/base.h.orig	Wed Oct  1 23:53:39 2003
+++ lib/libxview/base/base.h	Wed Oct  1 23:53:39 2003
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
 #ifndef SUNOS41
+#if !(defined(BSD) && (BSD >= 199103))
 #define XV_OS_SVR4
-#define XV_USE_TTCOMPAT
 #define SYSV_WAIT 
 #define SYSV_UCONTEXT 
+#endif
+#define XV_USE_TTCOMPAT
 #define XV_USE_XVFCNTL 
 #endif
  
