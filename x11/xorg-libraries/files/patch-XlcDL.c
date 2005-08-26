--- lib/X11/XlcDL.c.orig	Mon Aug 15 21:55:16 2005
+++ lib/X11/XlcDL.c	Mon Aug 15 21:56:02 2005
@@ -56,11 +56,13 @@
 #include "XlcPublic.h"
 #include "XlcPubI.h"
 
+#if !defined(__FreeBSD__)
 #if defined(_LP64)  && defined(__sparcv9)
 # define	_MACH64_NAME		"sparcv9"
 #else
 # undef _MACH64_NAME
 #endif /* defined(_LP64)  && defined(__sparcv9) */
+#endif
 
 #ifdef _MACH64_NAME
 #  define	_MACH64_NAME_LEN	(sizeof (_MACH64_NAME) - 1)
