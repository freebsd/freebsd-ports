--- lib/X11/XlcDL.c.orig	Sun Dec  1 23:17:32 2002
+++ lib/X11/XlcDL.c	Sun Dec  1 23:17:11 2002
@@ -60,7 +60,12 @@
 #define	_MACH64_NAME		"sparcv9"
 #define	_MACH64_NAME_LEN	(sizeof (_MACH64_NAME) - 1)
 #else  /* !defined(__sparcv9) */
+#if defined(__ia64__)
+#define _MACH64_NAME		"ia64"
+#define _MACH64_NAME_LEN        (sizeof (_MACH64_NAME) - 1)
+#else  /* !defined(__ia64__) */
 #error "Unknown architecture"
+#endif /* defined(__ia64__) */
 #endif /* defined(__sparcv9) */
 #endif /* _LP64 */
 
