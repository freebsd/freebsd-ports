--- lib/libxview/frame/fm_impl.h.orig	Tue Jun 29 00:16:15 1993
+++ lib/libxview/frame/fm_impl.h	Sun Oct 12 20:13:46 2003
@@ -17,12 +17,17 @@
 #define _frame_impl_h_already_included
 
 /* standard includes */
+#ifdef NULL
+#undef NULL
+#endif
 #ifndef FILE
 #ifndef SVR4
-#undef NULL
-#endif SVR4
+#endif /* SVR4 */
 #include <stdio.h>
-#endif FILE
+#ifndef NULL
+#define NULL 0
+#endif
+#endif /* FILE */
 #include <sys/time.h>
 #ifdef OW_I18N
 #endif /* OW_I18N */
