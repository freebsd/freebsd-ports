--- src/regex/regcustom.h.orig	Thu Nov 25 21:03:13 2004
+++ src/regex/regcustom.h	Thu Nov 25 21:03:29 2004
@@ -76,6 +76,11 @@
 #endif
 #define __REG_NOFRONT           /* don't want regcomp() and regexec() */
 #define _ANSI_ARGS_(x)          x
+
+#ifdef __FreeBSD__
+#define re_comp wx_re_comp
+#define re_exec wx_re_exec
+#endif
 /* --- end --- */
 
 /* internal character type and related */
