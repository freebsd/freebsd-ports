--- src/util/gradient.h.orig	2026-02-05 13:15:45 UTC
+++ src/util/gradient.h
@@ -6,6 +6,12 @@
 
 #include "color.h"
 
+// Work around for C23 macros getting exposed into C11 code.
+// See: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=292960
+#ifdef SIZE_WIDTH
+#undef SIZE_WIDTH
+#endif
+ 
 //////////////////////////////////////////////////////////////////////
 // Gradient types read from config options, not associated to any area
 
