--- lib/libxview/misc/portable.h.orig	Tue Jun 29 14:16:34 1993
+++ lib/libxview/misc/portable.h	Sat Jan  9 23:19:57 1999
@@ -10,6 +10,7 @@
 #ifndef xview_portable_h_DEFINED
 #define xview_portable_h_DEFINED
 
+#include <sys/param.h>
 #include <xview/attr.h>
 
 #if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
@@ -24,6 +25,10 @@
 
 EXTERN_FUNCTION (Attr_avlist copy_va_to_av, (va_list valist, Attr_avlist avlist, Attr_attribute attr1));
 
+#ifdef __alpha__
+#define	NO_CAST_VATOAV
+#endif
+
 #ifdef NO_CAST_VATOAV
 #define AVLIST_DECL  Attr_attribute avarray[ATTR_STANDARD_SIZE];  \
                      Attr_avlist    avlist = avarray
@@ -70,7 +75,11 @@
 #define	XV_USE_TERMIOS
 #define	XV_USE_SVR4_PTYS
 #else	/* SVR4 */
+#if (defined(BSD) && (BSD >= 199103))
+#define XV_USE_TERMIOS
+#else
 #undef	XV_USE_TERMIOS
+#endif
 #undef	XV_USE_SVR4_PTYS
 #endif	/* SVR4 */
