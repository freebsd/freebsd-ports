--- src/regex/regex.h.orig	Thu Nov 25 21:02:55 2004
+++ src/regex/regex.h	Thu Nov 25 21:03:06 2004
@@ -115,7 +115,13 @@
 #endif
 #define __REG_NOFRONT           /* don't want regcomp() and regexec() */
 #define _ANSI_ARGS_(x)          x
+
+#ifdef __FreeBSD__
+#define re_comp wx_re_comp
+#define re_exec wx_re_exec
+#endif
 /* --- end --- */
+
 
 /*
  * interface types etc.
